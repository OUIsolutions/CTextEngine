
#include "CTextEngine.h"



int main(){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int age = 15;

    s->open(s,CTEXT_HTML);
        s->open(s,CTEXT_HEAD);
     
        s->close(s,CTEXT_HEAD);
        s->open(s,CTEXT_BODY);
            s->open(s,CTEXT_H1);
            if(age > 18)
                s->segment_text(s,"You are an adout");
            else if (age > 12)
                s->segment_text(s,"You are a child");
            else 
                s->segment_text(s,"You are a baby");
            s->close(s,CTEXT_H1);
        s->close(s,CTEXT_BODY);
    s->close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level = s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
   s->free(s);

}