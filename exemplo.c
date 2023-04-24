#include "doTheWorld.c"
#include "CTextEngine/CTextEngineMain.h"



struct CTextStack * create_html(const char *lang, const char *text){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->text(s,"<!DOCTYPE html>");
    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
            s->only$open(s,META,"charset=\"utf-8\"");
            s->only$open(s,META,"name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
            s->auto$close(s,IMG,"src = \"https://www.w3schools.com/images/w3schools_green.jpg\" alt=\"W3Schools.com\" width=\"104\" height=\"142\"");
            s->auto$close(s,BR,NULL);
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


struct CTextStack * create_yaml(int a1, int b1,int b2,int a3){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    
    s->format(s,"a1: %d",a1);
    s->segment(s);
    s->format(s,"a2:");  
    s->open(s,NULL);
        s->segment(s);
        s->format(s,"b1: %d",b1);
        s->segment(s);
        s->format(s,"b2: %d",b2);
    
    s->close(s,NULL);
    s->segment(s);
    s->format(s,"a3: %d",a3);
    

    return s;
}



int main(){

   struct CTextStack *s = create_yaml(1,2,3,4);
   printf("%s",s->rendered_text);
   dtw_write_string_file_content("test.html",s->rendered_text);
   s->free(s);

}