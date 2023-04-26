#include "CTextEngine/CTextEngineMain.h"
#include "doTheWorld.c"


int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    
    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
            s->only$open(s,META,"charset=\"UTF-8\"");
        s->close(s,HEAD);
        s->open(s,BODY);
            s->auto$close(s,INPUT,"type=\"text\" name=\"name\" value=\"value\"");
            s->open(s,H1);
                s->segment_text(s,"This is a text");
            s->close(s,H1);
            s->open(s,P);
                s->segment_format(s,"This is a formated  text:%s",text);
            s->close(s,P);

        s->close(s,BODY);
        
    s->close(s,HTML);
    
   printf("%s\n",s->rendered_text);
   dtw_write_string_file_content("test.html",s->rendered_text);
   int ident_level = s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
   s->free(s);

}
