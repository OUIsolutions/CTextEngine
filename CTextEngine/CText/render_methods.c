

void ctext_text(struct CText *self, const char *text){

    self->rendered_text_alocation_size+= strlen(text);
    self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
     ));

    strcat(self->rendered_text,text);
}


void ctext_segment(struct CText *self){


    self->text(self,self->line_breaker);



    for(int i=0;i<self->ident_level -1;i++){
        self->text(self,self->separator);
    }


}

void ctext_open_with_string_props(struct CText *self, const char *tag, const char *props){


    self->ident_level += 1;
    self->segment(self);

    self->text(self,"<");
    self->text(self,tag);

    if(props!=NULL){
        self->text(self," ");
        self->text(self,props);
    }
    self->text(self,">");
}

void ctext_open(struct CText *self, const char *tag){
    if(tag ==  NULL){
        self->ident_level += 1;
        self->segment(self);
        return;
    }

    self->open_with_string_props(self, tag, NULL);
}


void ctext_close(struct CText *self, const char *tag){



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


