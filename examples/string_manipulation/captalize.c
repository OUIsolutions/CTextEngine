#include "CTextEngineOne.c"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack_string(
            "    Test aaaa aa "
    );
    CTextStack *s2 =stack.captalize(s);
    printf("%s\n",s2->rendered_text);
    stack.free(s2);
    stack.free(s);
}