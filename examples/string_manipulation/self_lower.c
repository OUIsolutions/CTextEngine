#include "CTextEngineOne.c"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack_string(
            "       My String       "
    );

   stack.self_lower(s);
    printf("%s\n",s->rendered_text);
   stack.free(s);
}