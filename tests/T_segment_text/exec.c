#include "../CTextEngine_test.h"
int main(){
   struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   s->segment_text(s,"test element");
   printf("%s\n",s->rendered_text);
   s->free(s);

}