

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStackModule m = newCTextStackModule();
    CTextArrayModule v = newCTextArrayModule();

    CTextArray * test = newCTextArray();

    v.append_string(test,"aaaaa");
    v.append_string(test,"aaaaa");
    v.append_string(test,"aaaaa");
    v.represent(test);

    v.free(test);
}