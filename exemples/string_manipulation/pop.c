#include "CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    

    CTextStack *s = newCTextStack_string("my string");
    //remove the first char
    CTextStack *start =stack.pop(s,0,0);
    printf("start:%s\n",start->rendered_text);


    //remove the second char and third times
    CTextStack *middle =stack.pop(s,1,2);
    printf("midle:%s\n",middle->rendered_text);


    //remove the end char
    CTextStack *end =stack.pop(s,-2,-1);
    printf("end:%s\n",end->rendered_text);


   stack.free(s);
   stack.free(start);
   stack.free(middle);
   stack.free(end);

}