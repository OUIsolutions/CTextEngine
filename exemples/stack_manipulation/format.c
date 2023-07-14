
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack_string_empty();
    int age = 20;
    const char *name = "John";
    m.format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
    m.free(s);

}