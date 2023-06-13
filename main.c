#include "CTextEngine.h"



int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack("", "");

    s->segment_format(s," %li",1);
    printf("%s",s->rendered_text);

}