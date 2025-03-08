
#include "CTextEngineOne.c"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack_string("my string");
    printf("%s",s->rendered_text);
   stack.free(s);
}