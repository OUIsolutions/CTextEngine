

#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *src = "img.com";
    stack.auto_close_format(s,CTEXT_IMG,"src=\"%s\"",src);
    printf("%s\n",s->rendered_text);
    stack.free(s);


}
