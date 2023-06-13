

#include "CTextEngine/CTextEngineMain.h"



int main(){

    CTextStack *s = newCTextStack("", "");
    s->segment_text(s,"ddd");
    s->segment_text(s,"ddd");
    s->segment_text(s,"ddd");
    printf("%i\n",s->size);
    printf("%s\n",s->rendered_text);



}