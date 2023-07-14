
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    int age = 20;
    const char *name = "John";
   m.segment_format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
   m.free(s);
}