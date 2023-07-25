
#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    struct CTextStack *s = newCTextStack_string("my string");
    printf("%s",s->rendered_text);
    m.free(s);
}