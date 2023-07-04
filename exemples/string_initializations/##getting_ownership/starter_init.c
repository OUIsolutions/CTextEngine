
#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    char *old = strdup("my string");
    struct CTextStack *s = newCTextStack_string_getting_ownership(old);
    printf("%s",s->rendered_text);
    m.free(s);
}