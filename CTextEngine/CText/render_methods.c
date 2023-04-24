

void ctext_text(struct CTextStack *self, const char *text){

    self->rendered_text_alocation_size+= strlen(text);
    self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
     ));

    strcat(self->rendered_text,text);
}


void ctext_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}

void ctext_segment(struct CTextStack *self){

    self->text(self,self->line_breaker);

    for(int i=0;i<self->ident_level -1;i++){
        self->text(self,self->separator);

    }


}

void ctext_$open(struct CTextStack *self, const char *tag, const char *format,...){


    self->ident_level += 1;
    self->segment(self);

    self->text(self,"<");
    self->text(self,tag);


    if(format!=NULL){
        self->text(self," ");
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    self->text(self,">");
}

void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){
        self->ident_level += 1;
        self->segment(self);
        return;
    }

    self->$open(self, tag, NULL);
}


void ctext_close(struct CTextStack *self, const char *tag){



    if(tag==NULL){
        self->ident_level -= 1;
        self->segment(self);
        return;
    }

    self->segment(self);
    self->ident_level -= 1;



    self->text(self,"</");
    self->text(self,tag);
    self->text(self,">");
}


