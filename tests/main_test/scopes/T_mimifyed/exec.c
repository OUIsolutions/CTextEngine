
#include "../../../CTextEngine.h"


int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    const char *lang = "en";
    const char *text = "text exemple";
    const char *breakline = "";
    const char *separator = "";
    CTextStack *s = stack.newStack(breakline, separator);

  stack.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
      stack.open(s,CTEXT_HEAD);
     
      stack.close(s,CTEXT_HEAD);
      stack.open(s,CTEXT_BODY);
          stack.open(s,CTEXT_H1);
              stack.segment_text(s,"This is a text");
          stack.close(s,CTEXT_H1);
          stack.open(s,CTEXT_P);
              stack.segment_format(s,"This is a formated  text  %s",text);
          stack.close(s,CTEXT_P);

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