

void private_ctext_text(struct CText *self, const char *text){
    self->rendered_text_alocation_size+= strlen(text);
    self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
     ));

    strcat(self->rendered_text,text);
}


void private_ctext_cat_separator(struct CText *self, bool break_line){

    if(break_line){
        self->text(self,self->line_breaker);
    }

    for(int i=0;i<self->ident_level;i++){
        self->text(self,self->separator);
    }


}

void private_ctext_$open(struct CText *self, const char *tag, const char *props){
    self->cat_separator(self,true);

    self->ident_level += 1;

    self->text(self,"<");
    self->text(self,tag);

    if(props!=NULL){
        self->text(self," ");
        self->text(self,props);
    }
    self->text(self,">");
}

void private_ctext_open(struct CText *self, const char *tag){

    if(tag==NULL){
        self->cat_separator(self,false);
        self->ident_level += 1;
        return;
    }

    self->$open(self,tag,NULL);
}

void private_ctext_close(struct CText *self, const char *tag){

    self->ident_level -= 1;
    if(tag==NULL){
        self->cat_separator(self,false);
        return;
    }
    self->cat_separator(self,true);
    self->text(self,"</");
    self->text(self,tag);
    self->text(self,">");
}


