#include "doTheWorld.c"
#include "CTextEngine/CTextEngineMain.h"



struct CTextStack * create_html(const char *lang, const char *text){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->text(s,"<!DOCTYPE html>");
    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
            
            s->only$open(s,META,"charset=\"utf-8\"");
            s->only$open(s,META,"name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");


            s->open(s,TITLE);
                s->text(s,"This is a title");
            s->close(s,TITLE);
        s->close(s,HEAD);

        s->open(s,BODY);
            s->open(s,H1);
                s->text(s,"This is an Tag");
            s->close(s,H1);
            s->open(s,P);
                s->format(s,"This is a %s",text);
            s->close(s,P);
        s->close(s,BODY);
    s->close(s,HTML);

    
    return s;
}



int main(){

   struct CTextStack *s = create_html("en","test");
   printf("%s",s->rendered_text);
   dtw_write_string_file_content("test.html",s->rendered_text);
   s->free(s);

}