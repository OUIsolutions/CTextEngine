//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CText.c"




struct CText *vd;
SET_MAIN_STACK(vd);


void create_html(const char *props, int data){
    
    struct CText *s = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    s->open(s,HTML);
    
        s->open(s,BODY);
          
            s->open(s,H1);
            
                s->text(s,"Hello World");
          
            s->close(s,H1);
     
        s->close(s,BODY);
   
    s->close(s,HTML);



    return vd;
}



int main(){
    vd = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    create_html("aaaaaaa",20);
    printf("%s",vd->rendered_text);
    vd->free(vd);

}