

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStack *s = newCTextStack_string("meu nome é #nome# aaaaaa");
    CTextStack *formated = s->replace(s,"#nome#","mateus");
    printf("%s\n",formated->rendered_text);
    s->free(s);
}