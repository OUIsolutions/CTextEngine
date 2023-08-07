
#include "../../../CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    struct CTextStack *s = stack.newStack_string_empty();

  stack.text(s,"test element");
   printf("%s\n",s->rendered_text);
 stack.free(s);

}