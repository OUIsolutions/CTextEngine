






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







