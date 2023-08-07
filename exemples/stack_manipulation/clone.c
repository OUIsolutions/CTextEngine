
#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    CTextStack *s = stack.newStack_string("my string");
    CTextStack *s1 =stack.clone(s);
    printf("%s\n",s->rendered_text);
    printf("%s\n",s1->rendered_text);
   stack.free(s);
   stack.free(s1);

}