

#include "CTextEngine/CTextEngineMain.h"

int main(){
    CTextStack *s = newCTextStack_string_empty();
    s->text(s,"aaaaaaaaaaa");
    s->self_insert_at(s,1,"B");
    s->represent(s);
    s->free(s);
}
