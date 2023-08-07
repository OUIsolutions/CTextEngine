#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    char *name  = "Mateus";
    int age = 26;
    double height = 1.81;


    CTextStack *s = newCTextStack_string(
            "my name is @name and my @age and I am @height"
    );

   stack.self_replace(s,"@name",name);
   stack.self_replace_long(s,"@age",age);
   stack.self_replace_double(s,"@height",height);
    printf("%s",s->rendered_text);

   stack.free(s);


}//
// Created by jurandi on 04-07-2023.
//
