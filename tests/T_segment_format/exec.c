
#include "../CTextEngine_test.h"

int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    int age = 20;
    const char *name = "John";
    s->segment_format(s,"Hes name is %s, he is %i years old ",name,age);
    printf("%s\n",s->rendered_text);
    s->free(s);
}