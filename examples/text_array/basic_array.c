#include "CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();

    CTextArray  *e = ctext.array.newArray();

    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");

    for(int i = 0;  i < e->size; i++){
        CTextStack *s = e->stacks[i];
        ctext.stack.self_upper(s);
    }


    CTextStack *formated = ctext.array.join(e,",");
    ctext.stack.represent(formated);
    ctext.stack.free(formated);

    ctext.array.free(e);

}