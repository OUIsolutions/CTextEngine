#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack_string("my string");
    //remove the first char
    CTextStack *start = m.pop(s,0,0);
    printf("start:%s\n",start->rendered_text);


    //remove the second char and third times
    CTextStack *middle = m.pop(s,1,2);
    printf("midle:%s\n",middle->rendered_text);


    //remove the end char
    CTextStack *end = m.pop(s,-2,-1);
    printf("end:%s\n",end->rendered_text);


    m.free(s);
    m.free(start);
    m.free(middle);
    m.free(end);

}