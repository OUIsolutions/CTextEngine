#include "CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "    My String      "
    );

    CTextStack *s2 = m.upper(s);
    printf("%s\n",s2->rendered_text);
    m.free(s2);
    m.free(s);

}