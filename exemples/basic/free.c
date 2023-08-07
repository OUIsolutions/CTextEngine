#include "CTextEngine.h"
int main(){
    CTextNamespace ctext = newCTextNamespace();

    struct CTextStack *s = ctext.stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    ctext.stack.free(s);

}