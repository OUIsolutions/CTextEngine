

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStack *s = newCTextStack_string("meu nome é #nome#  #nome# e minha idade é #idade#");

    s->self_replace(s,"#nome#","Mateus");
    s->self_replace(s,"#idade#","26");
    s->represent(s);

    printf("index:%i\n",s->index_of(s,"skosmokm"));
    s->free(s);
}