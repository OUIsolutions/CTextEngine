
#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = newCTextStack_string_empty();
    int age = 20;
    const char *name = "John";
   stack.format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
   stack.free(s);

}