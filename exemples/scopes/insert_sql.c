
#include "CTextEngine.h"




int main(){
    CTextStackModule m = newCTextStackModule();

    const char *table = "users";
    const char *columns[] = {"name","email","passord"};
    const char *values[] = {"John","john@email.com","1234"};

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.format(s,"INSERT INTO '%s' (",table);
   m.open(s,NULL);
       m.segment_format(s,"'%s'",columns[0]);
        for(int i = 1; i < sizeof(columns)/ sizeof(char *) ; i++){
           m.format(s,",'%s'",columns[i]);
        }
   m.segment_text(s,")");
   m.close(s,NULL);

   m.segment_text(s,"VALUES (");
   m.open(s,NULL);    
       m.segment_format(s,"'%s'",values[0]);
        for(int i = 1; i < sizeof(values)/ sizeof(char *) ; i++){
           m.format(s,",'%s'",values[i]);
        }
   m.segment_text(s,")");
   m.close(s,NULL);
    

    printf("%s\n",s->rendered_text);

   m.free(s);
        

}