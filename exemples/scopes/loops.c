
#include "CTextEngine.h"



int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *names[] = {"name1","name2","name3","name4","name 5"};

   m.open(s,CTEXT_HTML);
       m.open(s,CTEXT_HEAD);
     
       m.close(s,CTEXT_HEAD);
       m.open(s,CTEXT_BODY);
            for(int i = 0; i < sizeof(names)/ sizeof(char *) ; i++){
               m.open(s,CTEXT_H1);
                   m.segment_text(s,names[i]);
               m.close(s,CTEXT_H1);
            }

       m.close(s,CTEXT_BODY);
   m.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
  m.free(s);

}