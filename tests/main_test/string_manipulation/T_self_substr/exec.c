
#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack_string("my string");
    //substr from beguinning
    m.self_substr(s,3,5);
    printf("midle:%s\n",s->rendered_text);
    m.free(s);

}