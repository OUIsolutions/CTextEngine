

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "myss.txt"
    );

    m.self_lower(s);
    printf("%d\n",m.ends_with(s,".json"));
    m.free(s);

}