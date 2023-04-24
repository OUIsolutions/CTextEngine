//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CTextStack.c"





struct CTextStack * create_html(const char *props, int data){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->open(s,HTML);

        s->open(s,BODY);

            s->open(s,H1);
            
                s->text(s,"Hello World");
                s->sprint(s,"value: %d",data);

            s->close(s,H1);
     
        s->close(s,BODY);
   
    s->close(s,HTML);



    return s;
}



int main(){

   struct CTextStack *s = create_html("aaa",20);
    printf("%s",s->rendered_text);
    s->free(s);

}