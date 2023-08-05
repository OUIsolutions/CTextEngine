#include "CTextEngine.h"

int main(){
    CTextArrayModule array = newCTextArrayModule();

    CTextArray  *e = newCTextArray();

    CTextStack *first = newCTextStack_string("aaa");
    CTextStack *second = newCTextStack_string("bbb");

    array.append(e,first);
    array.append(e,second);


    array.represent(e);

    array.free(e);

}