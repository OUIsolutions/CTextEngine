

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStack *s = newCTextStack("","");
    s->text(s,"mateus");

    CTextStack *s1 = s->substr(s, -50, -2);
    printf("%s",s1->rendered_text);

    s->free(s);
    s1->free(s1);

}