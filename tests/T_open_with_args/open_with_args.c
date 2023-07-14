#include "CTextEngine.h"

int main(){   
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *lang = "en";
    s->$open(s,CTEXT_HTML, "lang=\"%s\"",lang);
    s->close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
    s->free(s);
}