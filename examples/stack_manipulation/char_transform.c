
#include "CTextEngineOne.c"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack_string("my string");
    printf("%s\n",s->rendered_text);

    char *r = stack.self_transform_in_string_and_self_clear(s);
    printf("%s\n",r);
    free(r);

}