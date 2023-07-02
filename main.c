

#include "CTextEngine/CTextEngineMain.h"

int main(){
    
    CTextStack *s = newCTextStack_string_empty();
    CTextStack_text(s,"          Mateus            ");
    CTextStack_self_trim(s);
    //printf("%li\n",s->size);
    CTextStack_represent(s);
    
    CTextStack_free(s);
    



}
