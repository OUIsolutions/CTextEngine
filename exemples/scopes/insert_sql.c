
#include "CTextEngine.h"




int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    const char *table = "users";
    const char *columns[] = {"name","email","passord"};
    const char *values[] = {"John","john@email.com","1234"};

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   stack.format(s,"INSERT INTO '%s' (",table);
   stack.open(s,NULL);
       stack.segment_format(s,"'%s'",columns[0]);
        for(int i = 1; i < sizeof(columns)/ sizeof(char *) ; i++){
           stack.format(s,",'%s'",columns[i]);
        }
   stack.segment_text(s,")");
   stack.close(s,NULL);

   stack.segment_text(s,"VALUES (");
   stack.open(s,NULL);    
       stack.segment_format(s,"'%s'",values[0]);
        for(int i = 1; i < sizeof(values)/ sizeof(char *) ; i++){
           stack.format(s,",'%s'",values[i]);
        }
   stack.segment_text(s,")");
   stack.close(s,NULL);
    

    printf("%s\n",s->rendered_text);

   stack.free(s);
        

}