
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

    struct Person john;
    john.name = "John";
    john.age = 20;
    john.car.name = "Ferrari";
    john.car.year = 2020;

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->segment_format(s,"Name: %s\n",john.name);
    s->segment_format(s,"Age: %d\n",john.age);
    s->segment_text(s,"Car: ");
    s->open(s,NULL);
        s->segment_format(s,"Name: %s\n",john.car.name);
        s->segment_format(s,"Year: %d\n",john.car.year);
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