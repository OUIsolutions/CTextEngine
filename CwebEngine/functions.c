

void private_cweb_engine_add(const char *element){
    // Add to stack
    strcat(cweb_engine_stack,element);

}

void $FRAGMENT(const char *text){
    private_cweb_engine_add(text);
}

void $OPEN(const char *tag,const char *props){
    private_cweb_engine_add("<");
    private_cweb_engine_add(tag);

    if(props!=NULL){
        private_cweb_engine_add(" ");
        private_cweb_engine_add(props);

    }
    private_cweb_engine_add(">");
}

void $CLOSE(const char *tag,const char *props){
    private_cweb_engine_add("</");
    private_cweb_engine_add(tag);
    private_cweb_engine_add(">");
}


void cweb_engine_render(char *html){
    // Render stack
    strcpy(html,cweb_engine_stack);
}

void cweb_engine_clear_stack(){
    // Clear stack
    strcpy(cweb_engine_stack,"");
}


