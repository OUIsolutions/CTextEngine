

#include "CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();
    char *name  = "Mateus";
    int age = 26;
    double height = 1.81;


    CTextStack *s = newCTextStack_string(
            "my name is @name and my @age and I am @height"
    );

    CTextStack *name_replaced  = m.replace(s,"@name",name);
    CTextStack *age_replaced = m.replace_long(name_replaced,"@age",age);
    CTextStack  *heigh_replaced = m.replace_double(age_replaced,"@height",height);
    printf("%s",heigh_replaced->rendered_text);

    m.free(s);
    m.free(name_replaced);
    m.free(age_replaced);
    m.free(heigh_replaced);

}//
// Created by jurandi on 04-07-2023.
//
