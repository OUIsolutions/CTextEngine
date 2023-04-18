//
// Created by jurandi on 18-04-2023.
//
void private_cweb_engine_add(const char *element){
    // Add to stack
    strcat(cweb_engine_stack,element);

}
void FRAGMENT(const char *text){
    private_cweb_engine_add(text);
}
void OPEN(const char *tag,const char *props){
    private_cweb_engine_add("<");
    private_cweb_engine_add(tag);
    private_cweb_engine_add(" ");
    if(props!=NULL){
        private_cweb_engine_add(props);

    }
    private_cweb_engine_add(">");
}

void CLOSE(const char *tag,const char *props){
    private_cweb_engine_add("</");
    private_cweb_engine_add(tag);
    private_cweb_engine_add(">");
}


void cweb_engine_render(const char *html){
    // Render stack
    strcpy(cweb_engine_stack,html);

}

void cweb_engine_clear_stack(){
    // Clear stack
    strcpy(stack,"");
}


