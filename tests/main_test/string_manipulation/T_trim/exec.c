#include "../../../CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "    my string        "
    );

    CTextStack *s2 = m.trim(s);
    printf("%s\n",s2->rendered_text);
    m.free(s2);
    m.free(s);

}