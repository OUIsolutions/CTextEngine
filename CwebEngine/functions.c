



void private_cweb_engine_cat(const char *element){
    // Add to stack
    strcat(cweb_stack_pointer,element);

}


void private_add_separator(int ident_level){
    
    int i;
    private_cweb_engine_cat(CWEB_LINE_BREAKER);

    for(i=0;i<ident_level;i++){
        private_cweb_engine_cat(CWEB_SEPARATOR);
    }
}


void $OPEN(const char *tag,const char *props){
    
    private_add_separator(cweb_ident_level);

    cweb_ident_level += 1;
    private_cweb_engine_cat("<");
    private_cweb_engine_cat(tag);

    if(props!=NULL){
        private_cweb_engine_cat(" ");
        private_cweb_engine_cat(props);

    }
    private_cweb_engine_cat(">");
}


void TEXT(const char *text){
    private_cweb_engine_cat(text);
}
void INTEGER(int number){
   //convert int to string
    char str[12];
    sprintf(str, "%d", number);
    private_cweb_engine_cat(str);
}

void FLOAT(float number){
    //convert float to string
    char str[12];
    sprintf(str, "%f", number);
    private_cweb_engine_cat(str);
}


void BOOLEAN(int boolean){
    if(boolean){
        private_cweb_engine_cat("true");
    }else{
        private_cweb_engine_cat("false");
    }
}



void OPEN(const char *tag){
    
    private_add_separator(cweb_ident_level);

    cweb_ident_level += 1;
    private_cweb_engine_cat("<");
    private_cweb_engine_cat(tag);

    private_cweb_engine_cat(">");
}

void CLOSE(const char *tag){
    cweb_ident_level -= 1;
    private_add_separator(cweb_ident_level);
    private_cweb_engine_cat("</");
    private_cweb_engine_cat(tag);
    private_cweb_engine_cat(">");
}




