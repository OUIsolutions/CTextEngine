#include "../../../CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   ctext.stack.open(s,CTEXT_HTML);
   ctext.stack.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   ctext.stack.free(s);
}