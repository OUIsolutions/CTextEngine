#include "CTextEngineOne.c"
int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
 stack.segment_text(s,"test element");
   printf("%s\n",s->rendered_text);
 stack.free(s);

}