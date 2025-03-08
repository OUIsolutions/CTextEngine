#include "CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    CTextStack *s = stack.newStack_string("my string");
    //substr from beguinning

    CTextStack *start =stack.substr(s,0,2);
    printf("start:%s\n",start->rendered_text);

    CTextStack *middle =stack.substr(s,3,5);
    printf("midle:%s\n",middle->rendered_text);

    CTextStack *end =stack.substr(s,3,-1);
    printf("end:%s\n",end->rendered_text);

   stack.free(s);
   stack.free(start);
   stack.free(middle);
   stack.free(end);

}