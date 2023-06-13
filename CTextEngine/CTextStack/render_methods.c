
void private_ctext_text_double_size_if_reachs(struct CTextStack *self){
    

    while(self->rendered_text_size >= (self->rendered_text_alocation_size-2)){
      
        self->rendered_text_alocation_size  =  (self->rendered_text_alocation_size  * 2)+2;
        self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
        ));

    }
}
void CTextStack_text(struct CTextStack *self, const char *text){

    if (!text || !text[0]) {
        // Tratar caso de ponteiro nulo ou string vazia
        return;
    }

    size_t text_size = strlen(text);
    
    self->rendered_text_size += text_size;
    private_ctext_text_double_size_if_reachs(self);
    
    memcpy(
        self->rendered_text + self->rendered_text_size - text_size,
        text,
        text_size 
    );
    self->rendered_text[self->rendered_text_size] = '\0';
}

void private_CTextStack_segment_char(struct CTextStack *self, char t){
    self->rendered_text_size += 1;
    private_ctext_text_double_size_if_reachs(self);
    self->rendered_text[self->rendered_text_size-1] = t;
    self->rendered_text[self->rendered_text_size] = '\0';
}

void CTextStack_segment_text(struct CTextStack *self, const char *text){
    self->segment(self);
    self->text(self,text);
}


void CTextStack_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}

void CTextStack_segment_format(struct CTextStack *self, const char *format, ...){
    self->segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}


void CTextStack_segment(struct CTextStack *self){

    self->text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        self->text(self,self->separator);

    }


}

void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    private_CTextStack_segment_char(self, '<');
    self->text(self,tag);


    if(format!=NULL){
        private_CTextStack_segment_char(self, ' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    private_CTextStack_segment_char(self, '>');

    self->ident_level += 1;
}

void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    private_CTextStack_segment_char(self, '<');
    self->text(self,tag);


    if(format!=NULL){
        private_CTextStack_segment_char(self, ' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    private_CTextStack_segment_char(self, '>');


}
void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    private_CTextStack_segment_char(self, '<');
    self->text(self,tag);


    if(format!=NULL){
        private_CTextStack_segment_char(self, ' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    self->text(self,"/>");

}
void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }

    self->$open(self, tag, NULL);
}




void ctext_close(struct CTextStack *self, const char *tag){

    if(tag==NULL){
        self->ident_level -= 1;

        return;
    }
    self->ident_level -= 1;
    self->segment(self);


    self->text(self,"</");
    self->text(self,tag);
    private_CTextStack_segment_char(self, '>');
}


