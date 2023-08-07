
#include "CTextEngine.h"



int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *names[] = {"name1","name2","name3","name4","name 5"};

  stack.open(s,CTEXT_HTML);
      stack.open(s,CTEXT_HEAD);
     
      stack.close(s,CTEXT_HEAD);
      stack.open(s,CTEXT_BODY);
            for(int i = 0; i < sizeof(names)/ sizeof(char *) ; i++){
              stack.open(s,CTEXT_H1);
                  stack.segment_text(s,names[i]);
              stack.close(s,CTEXT_H1);
            }

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