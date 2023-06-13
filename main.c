#include "CTextEngine/CTextEngineMain.h"



int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack("", "");

    s->text(s,"aaaaaaaaaa");
    char *r = s->self_transform_in_string(s);

    printf("%s",r);
    free(r);

}