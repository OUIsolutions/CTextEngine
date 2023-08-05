#include "../../../CTextEngine.h"

int main(){
    CTextArrayModule array = newCTextArrayModule();
    CTextStackModule stack = newCTextStackModule();
    CTextArray  *e = newCTextArray();

    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");
    array.append_string(e,"aaaaa");

    CTextArray *upper_array = array.map(e,stack.upper);

    CTextStack *formated = array.join(upper_array,",");
    stack.represent(formated);
    stack.free(formated);

    array.free(upper_array);
    array.free(e);

}