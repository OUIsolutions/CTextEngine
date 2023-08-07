#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    

    CTextStack *s = stack.newStack_string(
            "my string"
    );

   stack.self_insert_at(s,2,"aaaaaa");
    printf("%s\n",s->rendered_text);
   stack.free(s);
}