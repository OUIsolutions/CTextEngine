#include "../../../CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "       my string       "
    );

    m.self_upper(s);
    printf("%s\n",s->rendered_text);
    m.free(s);
}