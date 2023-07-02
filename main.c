

#include "CTextEngine/CTextEngineMain.h"

int main(){

    CTextStackModule  m = newCTextStackModule();
    CTextStack *s = newCTextStack_string_empty();
    m.text(s,"          Mateus            ");
    m.self_trim(s);
    //printf("%li\n",s->size);
    m.represent(s);
    m.free(s);
    



}
