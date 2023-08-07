
#include "CTextEngine.h"



int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int age = 15;

   stack.open(s,CTEXT_HTML);
       stack.open(s,CTEXT_HEAD);
     
       stack.close(s,CTEXT_HEAD);
       stack.open(s,CTEXT_BODY);
           stack.open(s,CTEXT_H1);
            if(age > 18)
               stack.segment_text(s,"You are an adout");
            else if (age > 12)
               stack.segment_text(s,"You are a child");
            else 
               stack.segment_text(s,"You are a baby");
           stack.close(s,CTEXT_H1);
       stack.close(s,CTEXT_BODY);
   stack.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
  stack.free(s);

}