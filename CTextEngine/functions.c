

void ctext_get_stack_ownership(char *stack_pointer){
    ctext_old_stack_pointer = ctext_stack_pointer;
    ctext_stack_pointer = stack_pointer;
}
void ctext_release_stack_ownership(){
    ctext_stack_pointer = ctext_old_stack_pointer;
    ctext_ident_level = 0;
}

void private_ctext_engine_cat(const char *element){
    // Add to stack
    strcat(ctext_stack_pointer,element);

}



void private_add_separator(int ident_level,bool break_line){
    
    int i;
    if(break_line){
        private_ctext_engine_cat(CTEXT_LINE_BREAKER);
    }

    for(i=0;i<ident_level;i++){
        private_ctext_engine_cat(CTEXT_SEPARATOR);
    }
}


void $OPEN(const char *tag,const char *props){
    private_add_separator(ctext_ident_level,true);
    ctext_ident_level += 1;    

 

    private_ctext_engine_cat("<");
    private_ctext_engine_cat(tag);

    if(props!=NULL){
        private_ctext_engine_cat(" ");
        private_ctext_engine_cat(props);

    }
    private_ctext_engine_cat(">");
}


void TEXT(const char *text){
    private_ctext_engine_cat(text);
}
void CHAR(char character){
    char str[2] = {character,'\0'};
    private_ctext_engine_cat(str);
}
void INTEGER(int number){
   //convert int to string
    char str[12]="";
    sprintf(str, "%d", number);
    
    private_ctext_engine_cat(str);
}

void FLOAT(float number){
    //convert float to string
    char str[12] ="";
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

void SPRINT(const char *text,...){
   
    
   int text_size = strlen(text);
   va_list argptr;
   

   va_start(argptr, text);
    if(text[0] != '%'){
        CHAR(text[0]);
    }
    for(int i =1;i < text_size ;i++){
         char last_char =  text[i-1];
         char current_char =  text[i];
         
         if(last_char =='%'){
            if(current_char == 'd'){
                INTEGER(va_arg(argptr, int));
            }
            else if(current_char == 'f'){
                FLOAT(va_arg(argptr, double));
            }
            else if(current_char == 's'){
                TEXT(va_arg(argptr, char *));
            }
            else if(current_char == 'c'){
                CHAR(va_arg(argptr, int));

            }else if(current_char == 'b'){
                BOOLEAN(va_arg(argptr, int));
            }
            else {
                CHAR('%');
                CHAR(current_char);
            }
            
            continue;
        }
        if(current_char == '%'){
            continue;
        }

        CHAR(current_char);
         
    }

    va_end(argptr);
}

void OPEN(const char *tag){
    

    if(tag==NULL){
        private_add_separator(ctext_ident_level,false);
        ctext_ident_level += 1;
        return;
    }

    private_add_separator(ctext_ident_level,true);
    ctext_ident_level += 1;


    private_ctext_engine_cat("<");
    private_ctext_engine_cat(tag);

    private_ctext_engine_cat(">");
}

void CLOSE(const char *tag){
    ctext_ident_level -= 1;
    if(tag==NULL){
         private_add_separator(ctext_ident_level,false);
        return;
    }

    private_add_separator(ctext_ident_level,true);
    private_ctext_engine_cat("</");
    private_ctext_engine_cat(tag);
    private_ctext_engine_cat(">");
}




