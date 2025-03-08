#include "CTextEngineOne.c"

int main(){
    CTextNamespace ctext = newCTextNamespace();

    CTextArray  *e = ctext.array.newArray();

    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");
    ctext.array.append_string(e,"aaaaa");

    ctext.array.foreach(e,ctext.stack.self_upper);

    CTextStack *formated = ctext.array.join(e,",");
    ctext.stack.represent(formated);
    ctext.stack.free(formated);

    ctext.array.free(e);

}