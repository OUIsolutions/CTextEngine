#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();

    CTextArray  *e = ctext.array.newArray();

    CTextStack *first = ctext.stack.newStack_string("aaa");
    CTextStack *second = ctext.stack.newStack_string("bbb");

    ctext.array.append(e,first);
    ctext.array.append(e,second);


    ctext.array.represent(e);

    ctext.array.free(e);

}