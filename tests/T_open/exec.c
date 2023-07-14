#include "../CTextEngine_test.h"
int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->open(s,CTEXT_HTML);
    s->close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
    s->free(s);

}