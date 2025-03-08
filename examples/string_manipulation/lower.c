#include "CTextEngineOne.c"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack_string(
            "    My String      "
    );

    CTextStack *s2 =stack.lower(s);
    printf("%s\n",s2->rendered_text);
   stack.free(s2);
   stack.free(s);

}