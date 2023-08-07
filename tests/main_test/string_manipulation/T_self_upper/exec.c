#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    

    CTextStack *s = newCTextStack_string(
            "       my string       "
    );

   stack.self_upper(s);
    printf("%s\n",s->rendered_text);
   stack.free(s);
}