#include "../../../CTextEngine.h"

int main(){


    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *lang = "en";
  stack.$open(s,CTEXT_HTML, "lang=\"%s\"",lang);
  stack.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
  stack.free(s);
}