
#include "../../../CTextEngine.h"


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

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct Person john;
    john.name = "John";
    john.age = 20;
    john.car.name = "Ferrari";
    john.car.year = 2020;

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

  stack.format(s,"Name: %s",john.name);
  stack.segment_format(s,"Age: %d",john.age);
  stack.segment_text(s,"Car: ");
  stack.open(s,NULL);
      stack.segment_format(s,"Name: %s",john.car.name);
      stack.segment_format(s,"Year: %d",john.car.year);
  stack.close(s,NULL);
  
    printf("%s\n",s->rendered_text);

  stack.free(s);
        

}