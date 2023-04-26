
void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    int text_size = strlen(format);


    if(format[0] != '%'){
        char element[2] = {format[0],'\0'};
        stack->text(stack,element);
    }

    for(int i =1;i < text_size ;i++){
        char last_char =  format[i-1];
        char current_char =  format[i];

        if(last_char =='%'){

            if(current_char == 'd' || current_char == 'i'){
                char result[10];
                sprintf(result,"%d", va_arg(argptr,int));
                stack->text(stack,result);
            }

            else if(current_char == 'c'){
                char result = va_arg(argptr,int);
                private_ctext_segment_char(stack,result);
            }
            

            else if(current_char == 'b'){
                bool value = va_arg(argptr,int);
                if(value){
                    stack->text(stack,"true");
                }else{
                    stack->text(stack,"false");
                }
            }
            else if(current_char == 's'){
                const char *value = va_arg(argptr,const char*);
                stack->text(stack,value);
            }
            else{
                
                private_ctext_segment_char(stack,current_char);
            }



            continue;
        }

        if(current_char == '%'){
            continue;
        }

        char element[2] = {current_char,'\0'};
        stack->text(stack,element);
    }

    va_end(argptr);
}