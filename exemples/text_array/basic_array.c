#include "CTextEngine.h"

int main(){
    CTextArrayModule ma = newCTextArrayModule();
    CTextStackModule ms = newCTextStackModule();
    CTextArray  *e = newCTextArray();

    ma.append_string(e,"aaaaa");
    ma.append_string(e,"aaaaa");
    ma.append_string(e,"aaaaa");
    ma.append_string(e,"aaaaa");

    for(int i = 0;  i < e->size; i++){
        CTextStack *s = e->stacks[i];
        ms.self_upper(s);
    }


    CTextStack *formated = ma.join(e,",");
    ms.represent(formated);
    ms.free(formated);

    ma.free(e);

}