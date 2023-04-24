
#include "CTextEngine.h"



int main(){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *names[] = {"name1","name2","name3","name4","name 5"};



    s->open(s,HTML);
        s->open(s,HEAD);
     
        s->close(s,HEAD);
        s->open(s,BODY);
            for(int i = 0; i < sizeof(names)/ sizeof(char *) ; i++){
                s->open(s,H1);
                    s->segment_text(s,names[i]);
                s->close(s,H1);
            }

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