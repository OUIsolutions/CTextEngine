

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStack *s = newCTextStack_string("meu nome é #nome#  #nome# e minha idade é #idade#");

    s->self_replace(s,"#nome#","Mateus");
    s->self_replace(s,"#idade#","26");
    s->represent(s);

    CTextStack *s1 = s->clone(s);

    printf("%s\n",s1->rendered_text);
    s1->free(s1);
    s->free(s);
}