



void private_ctext_engine_cat(const char *element){
    // Add to stack
    strcat(ctext_stack_pointer,element);

}


void private_add_separator(int ident_level){
    
    int i;
    private_ctext_engine_cat(CTEXT_LINE_BREAKER);

    for(i=0;i<ident_level;i++){
        private_ctext_engine_cat(CTEXT_SEPARATOR);
    }
}


void $OPEN(const char *tag,const char *props){
    
    private_add_separator(ctext_ident_level);

    ctext_ident_level += 1;
    private_ctext_engine_cat("<");
    private_ctext_engine_cat(tag);

    if(props!=NULL){
        private_ctext_engine_cat(" ");
        private_ctext_engine_cat(props);

    }
    private_ctext_engine_cat(">");
}

void SPRINT(const char *text,...){
   
    va_list argptr;


    for(int i =1;i < strlen(text);i++){
        char last_char = text[i-1];     
        char current_char = text[i];
        
        if(last_char == '%'){
            switch(current_char){
                case 's':
                    TEXT(va_arg(argptr,char *));
                    break;
                case 'd':
                    INTEGER(va_arg(argptr,int));
                    break;
                case 'f':
                    FLOAT(va_arg(argptr,double));
                    break;
                case 'b':
                    BOOLEAN(va_arg(argptr,int));
                    break;
                default:
                    TEXT("%");
                    TEXT(&current_char);
                    break;
            }
            i++;
            continue;
        }
        if(current_char != '%'){
            TEXT(&current_char);
        }
    }
}

void TEXT(const char *text){
    private_ctext_engine_cat(text);
}
void INTEGER(int number){
   //convert int to string
    char str[12];
    sprintf(str, "%d", number);
    private_ctext_engine_cat(str);
}

void FLOAT(float number){
    //convert float to string
    char str[12];
    sprintf(str, "%f", number);
    private_ctext_engine_cat(str);
}


void BOOLEAN(int boolean){
    if(boolean){
        private_ctext_engine_cat("true");
    }else{
        private_ctext_engine_cat("false");
    }
}



void OPEN(const char *tag){
    
    private_add_separator(ctext_ident_level);

    ctext_ident_level += 1;
    private_ctext_engine_cat("<");
    private_ctext_engine_cat(tag);

    private_ctext_engine_cat(">");
}

void CLOSE(const char *tag){
    ctext_ident_level -= 1;
    private_add_separator(ctext_ident_level);
    private_ctext_engine_cat("</");
    private_ctext_engine_cat(tag);
    private_ctext_engine_cat(">");
}




