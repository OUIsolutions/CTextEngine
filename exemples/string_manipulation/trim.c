#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    

    CTextStack *s = stack.newStack_string(
            "    my string        "
    );

    CTextStack *s2 =stack.trim(s);
    printf("%s\n",s2->rendered_text);
   stack.free(s2);
   stack.free(s);

}