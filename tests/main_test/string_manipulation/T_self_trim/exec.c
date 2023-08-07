#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    

    CTextStack *s = stack.newStack_string(
            "       my string       "
    );

   stack.self_trim(s);
    printf("%s\n",s->rendered_text);
   stack.free(s);
}