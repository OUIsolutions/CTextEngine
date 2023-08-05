#include "CTextEngine.h"

int main(){
    CTextArrayModule array = newCTextArrayModule();
    CTextStackModule stack = newCTextStackModule();
    CTextArray  *e = newCTextArray();

    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");

    for(int i = 0;  i < e->size; i++){
        CTextStack *s = e->stacks[i];
        stack.self_upper(s);
    }


    CTextStack *formated = array.join(e,",");
    stack.represent(formated);
    stack.free(formated);

    array.free(e);

}