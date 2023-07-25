
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack_string_empty();

   m.text(s,"test element");
   printf("%s\n",s->rendered_text);
  m.free(s);

}