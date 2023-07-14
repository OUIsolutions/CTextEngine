
#include "../../../CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack_string("my string");

    //remove the second char and third times
    m.self_pop(s,1,2);
    printf("midle:%s\n",s->rendered_text);

    m.free(s);


}