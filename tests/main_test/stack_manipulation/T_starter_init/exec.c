
#include "../../../CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = newCTextStack_string("my string");
    printf("%s",s->rendered_text);
   stack.free(s);
}