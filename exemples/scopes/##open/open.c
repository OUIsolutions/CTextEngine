#include "../../../CTextEngine.h"
int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.open(s,CTEXT_HTML);
   m.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   m.free(s);

}