



void private_cweb_engine_add(const char *element){
    // Add to stack
    strcat(cweb_stack_pointer,element);

}


void private_cweb_engine_add_separator(int ident_level){
    
    int i;
    private_cweb_engine_add(CWEB_LINE_BREAKER);

    for(i=0;i<ident_level;i++){
        private_cweb_engine_add(CWEB_SEPARATOR);
    }
}


void $OPEN(const char *tag,const char *props){
    
    private_cweb_engine_add_separator(cweb_ident_level);

    cweb_ident_level += 1;
    private_cweb_engine_add("<");
    private_cweb_engine_add(tag);

    if(props!=NULL){
        private_cweb_engine_add(" ");
        private_cweb_engine_add(props);

    }
    private_cweb_engine_add(">");
}


void FRAGMENT(const char *text){
    private_cweb_engine_add(text);
}


void OPEN(const char *tag){
    
    private_cweb_engine_add_separator(cweb_ident_level);

    cweb_ident_level += 1;
    private_cweb_engine_add("<");
    private_cweb_engine_add(tag);

    private_cweb_engine_add(">");
}

void CLOSE(const char *tag){
    cweb_ident_level -= 1;
    private_cweb_engine_add_separator(cweb_ident_level);
    private_cweb_engine_add("</");
    private_cweb_engine_add(tag);
    private_cweb_engine_add(">");
}




