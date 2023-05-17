
#include "CTextEngine/CTextEngineMain.h"
#include "doTheWorld.h"


int main(){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *teste = dtw_load_string_file_content("amalgamate.py");

    s->segment_text(s, teste);


    dtw_write_string_file_content("teste.html",s->rendered_text);

}