#include "CTextEngine.h"
int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
 stack.segment_text(s,"test element");
   printf("%s\n",s->rendered_text);
 stack.free(s);

}