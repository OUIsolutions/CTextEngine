#include "CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();
    char *name  = "Mateus";
    int age = 26;
    double height = 1.81;


    CTextStack *s = newCTextStack_string(
            "my name is @name and my @age and I am @height"
    );

    m.self_replace(s,"@name",name);
    m.self_replace_long(s,"@age",age);
    m.self_replace_double(s,"@height",height);
    printf("%s",s->rendered_text);

    m.free(s);


}//
// Created by jurandi on 04-07-2023.
//
