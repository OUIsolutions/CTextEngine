
#include "CTextEngine.h"



int main(){
    CTextStackModule m = newCTextStackModule();
    for(int i = 0; i < 1000;i++){
        CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
        m.free(s);
    }



}