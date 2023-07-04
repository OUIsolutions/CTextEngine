#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack_string("my string");
    //substr from beguinning

    CTextStack *start = m.substr(s,0,2);
    printf("start:%s\n",start->rendered_text);

    CTextStack *middle = m.substr(s,3,5);
    printf("midle:%s\n",middle->rendered_text);

    CTextStack *end = m.substr(s,3,-1);
    printf("end:%s\n",end->rendered_text);

    m.free(s);
    m.free(start);
    m.free(middle);
    m.free(end);

}