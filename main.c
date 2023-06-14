

#include "CTextEngine/CTextEngineMain.h"

int main(){


    char *test = strdup("Mateus");
    CTextStack *s = newCTextStack_string_getting_ownership(test);
    s->self_pop(s, -2, -2);
    s->represent(s);

    s->free(s);

}