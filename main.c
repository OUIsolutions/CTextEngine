

#include "CTextEngine/CTextEngineMain.h"

int main(){
    
    CTextStack *s = newCTextStack_string_empty();
    s->text(s,"          Mateus            ");
    s->self_trim(s);
    //printf("%li\n",s->size);
    //s->represent(s);
    
    s->free(s);
    



}
