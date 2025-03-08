

#include "CTextEngineOne.c"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    char *name  = "Mateus";
    int age = 26;
    double height = 1.81;


    CTextStack *s = stack.newStack_string(
            "my name is @name and my @age and I am @height"
    );

    CTextStack *name_replaced  =stack.replace(s,"@name",name);
    CTextStack *age_replaced =stack.replace_long(name_replaced,"@age",age);
    CTextStack  *heigh_replaced =stack.replace_double(age_replaced,"@height",height);
    printf("%s",heigh_replaced->rendered_text);

   stack.free(s);
   stack.free(name_replaced);
   stack.free(age_replaced);
   stack.free(heigh_replaced);

}//
// Created by jurandi on 04-07-2023.
//
