
#include "CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    char *old = strdup("my string");
    struct CTextStack *s = stack.newStack_string_getting_ownership(old);
    printf("%s",s->rendered_text);
   stack.free(s);
}