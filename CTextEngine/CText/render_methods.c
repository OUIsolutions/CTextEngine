

void ctext_text(struct CTextStack *self, const char *text){

    self->rendered_text_alocation_size+= strlen(text);
    self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
     ));

    strcat(self->rendered_text,text);
}

void ctext_format(struct CTextStack *self, const char *format, ...){

    int text_size = strlen(format);
    va_list argptr;

    va_start(argptr, format);
    if(format[0] != '%'){
        char element[2] = {format[0],'\0'};
        self->text(self,element);
    }

    for(int i =1;i < text_size ;i++){
        char last_char =  format[i-1];
        char current_char =  format[i];

        if(last_char =='%'){

            if(current_char == 'd' || current_char == 'i'){
                char result[10];
                sprintf(result,"%d", va_arg(argptr,int));
                self->text(self,result);
            }

            else if(current_char == 'c'){

                char result = va_arg(argptr,int);
                char element [2] = {result,'\0'};
                self->text(self,element);
            }

            else if(current_char == 'b'){
                bool value = va_arg(argptr,int);
                if(value){
                    self->text(self,"true");
                }else{
                    self->text(self,"false");
                }
            }
            else if(current_char == 's'){
                const char *value = va_arg(argptr,const char*);
                self->text(self,value);
            }
            else{
                char element[2] = {current_char,'\0'};
                self->text(self,element);
            }



            continue;
        }

        if(current_char == '%'){
            continue;
        }

        char element[2] = {current_char,'\0'};
        self->text(self,element);
    }

    va_end(argptr);
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

    if(props!=NULL){
        self->text(self," ");
        self->text(self,props);
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


