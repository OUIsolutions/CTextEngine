#include "CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();


    CTextStack *s = newCTextStack_string(
            "my string"
    );

    m.self_insert_at(s,2,"aaaaaa");
    printf("%s\n",s->rendered_text);
    m.free(s);
}