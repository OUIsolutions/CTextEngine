

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStack *s = newCTextStack_string("meu nome é #nome# e minha #idade# é");

    s->self_replace(s,"#nome#","Mateus");
    s->self_replace(s,"#idade#","26");
    s->represent(s);

    s->free(s);
}