#include "../../../CTextEngine.h"

int main(){
    CTextArrayModule array = newCTextArrayModule();
    CTextStackModule stack = newCTextStackModule();
    CTextArray  *e = newCTextArray();

    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");

    array.foreach(e,stack.self_upper);

    CTextStack *formated = array.join(e,",");
    stack.represent(formated);
    stack.free(formated);

    array.free(e);

}