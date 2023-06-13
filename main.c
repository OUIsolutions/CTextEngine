#include "CTextEngine/CTextEngineMain.h"



int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack("", "");
    struct  CTextStack *s1 = newCTextStack("","");
    s1->text(s1,"valor s aaaaaaaa2");
    s->text(s,"valor s");

    s->format(s," copiado %tc final",s1);

    printf("%s",s->rendered_text);
    s->free(s);


}