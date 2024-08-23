

#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *name = "viewport";
  stack.only_open_format(
        s,
        CTEXT_META,
        "name=\"%s\" content=\"width=device-width, initial-scale=1.0",
        name
    );
    printf("%s\n",s->rendered_text);
  stack.free(s);

}
