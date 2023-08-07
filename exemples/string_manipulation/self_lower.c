#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = newCTextStack_string(
            "       My String       "
    );

   stack.self_lower(s);
    printf("%s\n",s->rendered_text);
   stack.free(s);
}