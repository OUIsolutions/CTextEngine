
#include "CTextEngineOne.c"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    int age = 20;
    const char *name = "John";
  stack.segment_format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
  stack.free(s);
}