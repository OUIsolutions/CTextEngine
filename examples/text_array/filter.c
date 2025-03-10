#include "CTextEngineOne.c"

int main(){
    CTextNamespace ctext = newCTextNamespace();

    CTextArray  *e = ctext.array.newArray();

    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"123");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"444");

    CTextArray *num_array = ctext.array.filter(e,ctext.stack.is_a_num);

    CTextStack *formated = ctext.array.join(num_array,",");
    ctext.stack.represent(formated);
    ctext.stack.free(formated);

    ctext.array.free(num_array);
    ctext.array.free(e);

}