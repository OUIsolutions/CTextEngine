//
// Created by jurandi on 04-07-2023.
//
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack_string_empty();
    m.text(s,"my text");
    printf("%s",s->rendered_text);
    m.free(s);
}