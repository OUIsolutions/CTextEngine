
#include "../../../CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    CTextStack *s = newCTextStack_string("my string");
    //substr from beguinning
   stack.self_substr(s,3,5);
    printf("midle:%s\n",s->rendered_text);
   stack.free(s);

}