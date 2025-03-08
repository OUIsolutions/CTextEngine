#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;


    CTextStack *s = stack.newStack_string(
            " mateus moutinho queiroz"
    );
    stack.self_captalize(s);
    printf("%s",s->rendered_text);

   stack.free(s);


}//
// Created by jurandi on 04-07-2023.
//
