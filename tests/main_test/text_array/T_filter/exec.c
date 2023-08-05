#include "../../../CTextEngine.h"

int main(){
    CTextArrayModule array = newCTextArrayModule();
    CTextStackModule stack = newCTextStackModule();
    CTextArray  *e = newCTextArray();

    array.append_string(e,"aaaaa");
    array.append_string(e,"123");
    array.append_string(e,"aaaaa");
    array.append_string(e,"444");

    CTextArray *num_array = array.filter(e,stack.is_a_num);

    CTextStack *formated = array.join(num_array,",");
    stack.represent(formated);
    stack.free(formated);

    array.free(num_array);
    array.free(e);

}