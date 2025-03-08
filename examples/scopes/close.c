#include "CTextEngineOne.c"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   stack.open(s,CTEXT_HTML);
   stack.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   stack.free(s);
}