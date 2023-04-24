
#include "CTextEngine.h"



struct CTextStack * create_html(const char *lang, const char *text){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
     
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
                s->segment_text(s,"This is a text");
            s->close(s,H1);
            s->open(s,P);
                s->segment_format(s,"This is a formated  text  %s",text);
        s->close(s,BODY);
    s->close(s,HTML);

    
    return s;
}


int main(){

   struct CTextStack *s = create_html("en","text");
   printf("%s",s->rendered_text);

   s->free(s);

}