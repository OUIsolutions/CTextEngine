#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();

    CTextArray  *e = newCTextArray();

    CTextStack *first = newCTextStack_string("aaa");
    CTextStack *second = newCTextStack_string("bbb");

    ctext.array.append(e,first);
    ctext.array.append(e,second);


    ctext.array.represent(e);

    ctext.array.free(e);

}