
#include "../../../CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack_string("my string");
    printf("%s",s->rendered_text);

    char *r = m.self_transform_in_string_and_self_clear(s);
    printf("%s",r);
    free(r);

}