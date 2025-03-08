#include "CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();

    CTextArray  *e = ctext.array.newArray();

    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");

    CTextArray *upper_array = ctext.array.map(e,ctext.stack.upper);

    CTextStack *formated = ctext.array.join(upper_array,",");
    ctext.stack.represent(formated);
    ctext.stack.free(formated);

    ctext.array.free(upper_array);
    ctext.array.free(e);

}