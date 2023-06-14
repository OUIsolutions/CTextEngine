

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStack *s = newCTextStack_string("mateus");
    s->self_reverse(s);
    printf("%s\n",s->rendered_text);
    s->self_reverse(s);
    printf("%s\n",s->rendered_text);

    s->free(s);
}