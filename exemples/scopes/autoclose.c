

#include "../../CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *src = "img.com";
    m.auto$close(s,CTEXT_IMG,"src=\"%s\"",src);
    printf("%s\n",s->rendered_text);
    m.free(s);

}