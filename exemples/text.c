
#include "CTextEngine.h"

int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->text(s,"test element");
   printf("%s\n",s->rendered_text);
   s->free(s);

}