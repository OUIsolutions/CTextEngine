#include "../../../CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "       My String       "
    );

    m.self_lower(s);
    printf("%s\n",s->rendered_text);
    m.free(s);
}