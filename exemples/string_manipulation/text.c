
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

   m.text(s,"test element");
   printf("%s\n",s->rendered_text);
  m.free(s);

}