
#include "../../../CTextEngine.h"



int main(){
    CTextNamespace ctext = newCTextNamespace();

    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
  
   ctext.stack.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
       ctext.stack.open(s,CTEXT_HEAD);
        
       ctext.stack.close(s,CTEXT_HEAD);
       ctext.stack.open(s,CTEXT_BODY);
           ctext.stack.open(s,CTEXT_H1);
               ctext.stack.segment_text(s,"This is a text");
           ctext.stack.close(s,CTEXT_H1);
           ctext.stack.open(s,CTEXT_P);
               ctext.stack.segment_format(s,"This is a formated  text  %s",text);
           ctext.stack.close(s,CTEXT_P);

       ctext.stack.close(s,CTEXT_BODY);
   ctext.stack.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
       ctext.stack.free(s);
        return 1;
    }

  ctext.stack.free(s);

}