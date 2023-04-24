//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CTextStack.c"





struct CTextStack * create_html(const char *props, int data){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->$open(s,HTML,"teste=\"%s\"",props);
        s->open(s,BODY);
            s->open(s,H1);
                s->open(s,NULL);
                    s->text(s,"Hello World");
                    s->segment(s);
                    s->format(s, "int value: %d", data);
                    s->segment(s);
                    s->format(s, "string value: %s", props);
                    s->segment(s);
                    s->format(s, " %c %b %d %i %s", 'b', true, 33, 34, "aaa");
                s->close(s,NULL);
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