
#include "CTextEngine.h"


struct Car {
    const char *name;
    int year;
};

struct Person {
    const char *name;
    int age;
    struct Car car;

};


int main(){
    CTextStackModule m = newCTextStackModule();

    struct Person john;
    john.name = "John";
    john.age = 20;
    john.car.name = "Ferrari";
    john.car.year = 2020;

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

   m.format(s,"Name: %s",john.name);
   m.segment_format(s,"Age: %d",john.age);
   m.segment_text(s,"Car: ");
   m.open(s,NULL);
       m.segment_format(s,"Name: %s",john.car.name);
       m.segment_format(s,"Year: %d",john.car.year);
   m.close(s,NULL);
  
    printf("%s\n",s->rendered_text);
    int ident_level =s->ident_level;
    if(ident_level == 0){
            printf("all identation is ok\n");
        }else{
            printf("identation error\n");
            printf("unclosed tags: %d\n",ident_level);
        }
   m.free(s);
        

}