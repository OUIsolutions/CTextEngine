#include "../../CTextEngine.h"
int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.free(s);

}