//
// Created by jurandi on 04-07-2023.
//
#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    struct CTextStack *s = stack.newStack_string_empty();
   stack.text(s,"my text");
    printf("%s",s->rendered_text);
   stack.free(s);
}