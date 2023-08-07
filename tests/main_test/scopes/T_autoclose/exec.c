

#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *src = "img.com";
    ctext.stack.auto$close(s,CTEXT_IMG,"src=\"%s\"",src);
    printf("%s\n",s->rendered_text);
    ctext.stack.free(s);
   
    
}