

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "myss stringTTT 32"
    );

    m.self_lower(s);
    printf("%d\n",m.starts_with(s,"my"));
    m.free(s);

}