
#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack_string("my string");
    CTextStack *s1 = m.clone(s);
    printf("%s",s->rendered_text);
    printf("%s",s1->rendered_text);
    m.free(s);
    m.free(s1);

}