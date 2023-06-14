

#include "CTextEngine/CTextEngineMain.h"

int main(){


    char *test = strdup("Meu nome é #nome# e minha idade é #idade# ");
    CTextStack *s = newCTextStack_string_getting_ownership(test);


    s->self_replace(s,"#nome#","Mateus");
    s->self_replace(s,"#idade#","26");


    s->represent(s);

    s->free(s);

}