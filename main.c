

#include "CTextEngine/CTextEngineMain.h"
//#include "../../../CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();

    CTextStack *s = newCTextStack_string(
            "my name is @name and my @age"
    );

    CTextStack *name_replaced  = m.replace(s,"@name","Mateus");
    CTextStack *age_replaced = m.replace_long(name_replaced,"@age",26);



}