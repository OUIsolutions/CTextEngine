#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    const char *lang = "en";
    const char *text = "text exemple";
    const char *breakline = "";
    const char *separator = "";
    struct CTextStack *s = newCTextStack(breakline, separator);

   m.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
       m.open(s,CTEXT_HEAD);
     
       m.close(s,CTEXT_HEAD);
       m.open(s,CTEXT_BODY);
           m.open(s,CTEXT_H1);
               m.segment_text(s,"This is a text");
           m.close(s,CTEXT_H1);
           m.open(s,CTEXT_P);
               m.segment_format(s,"This is a formated  text  %s",text);
           m.close(s,CTEXT_P);

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