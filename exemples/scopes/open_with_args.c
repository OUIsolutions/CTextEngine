#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *lang = "en";
   m.$open(s,CTEXT_HTML, "lang=\"%s\"",lang);
   m.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   m.free(s);
}