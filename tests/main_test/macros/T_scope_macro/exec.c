#include "../../../CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *lang = "en";
    const char *text = "text exemple";
    CTextScope_format(s, CTEXT_HTML,"lang=\"%s\"",lang){
        CTextScope(s,CTEXT_HEAD){}
        CTextScope(s,CTEXT_BODY){
            CTextScope(s,CTEXT_H1){
                stack.segment_text(s,"This is a text");
            }
            CTextScope(s,CTEXT_P){
                stack.segment_format(s,"This is a formated  text  %s",text);

            }
        }
    }

    printf("%s\n",s->rendered_text);

    stack.free(s);
}
