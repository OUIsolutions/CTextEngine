//
// Created by jurandi on 18-04-2023.
//
#include "CwebEngine/CwebEngineMain.c"
#include <stdio.h>


void create_document(){
    OPEN(HTML,NULL);
        OPEN(BODY,NULL);
            OPEN(H1,NULL);
                FRAGMENT("Hello World");
            CLOSE(H1,NULL);
        CLOSE(BODY,NULL);
    CLOSE(HTML,NULL);
}

int main(){
   create_document();
   char result[100];
   cweb_engine_render(result);
   printf("%s",result);
}