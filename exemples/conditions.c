
#include "CTextEngine.h"



int main(){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int age = 15;

    s->open(s,HTML);
        s->open(s,HEAD);
     
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
            if(age > 18)
                s->segment_text(s,"You are an adout");
            else if (age > 12)
                s->segment_text(s,"You are a child");
            else 
                s->segment_text(s,"You are a baby");
            s->close(s,H1);
        s->close(s,BODY);
    s->close(s,HTML);

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