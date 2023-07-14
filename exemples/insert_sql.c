


#include "CTextEngine.h"




int main(){
    const char *table = "users";
    const char *columns[] = {"name","email","passord"};
    const char *values[] = {"John","john@email.com","1234"};

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->format(s,"INSERT INTO '%s' (",table);
    s->open(s,NULL);
        s->segment_format(s,"'%s'",columns[0]);
        for(int i = 1; i < sizeof(columns)/ sizeof(char *) ; i++){
            s->format(s,",'%s'",columns[i]);
        }
    s->segment_text(s,")");
    s->close(s,NULL);

    s->segment_text(s,"VALUES (");
    s->open(s,NULL);    
        s->segment_format(s,"'%s'",values[0]);
        for(int i = 1; i < sizeof(values)/ sizeof(char *) ; i++){
            s->format(s,",'%s'",values[i]);
        }
    s->segment_text(s,")");
    s->close(s,NULL);
    
    


  
    printf("%s\n",s->rendered_text);
    int ident_level = s->ident_level;
    if(ident_level == 0){
            printf("all identation is ok\n");
        }else{
            printf("identation error\n");
            printf("unclosed tags: %d\n",ident_level);
        }
    s->free(s);
        

}