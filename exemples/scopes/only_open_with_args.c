

#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *name = "viewport";
   m.only$open(
        s,
        CTEXT_META, 
        "name=\"%s\" content=\"width=device-width, initial-scale=1.0",
        name
    );
    printf("%s\n",s->rendered_text);
   m.free(s);

}