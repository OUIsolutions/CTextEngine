//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CwebEngine/CwebEngineMain.c"


void create_document(char *props){
    $OPEN(HTML,props);
        OPEN(BODY);
            OPEN(H1);
                FRAGMENT("Hello World");
            CLOSE(H1);
        CLOSE(BODY);
    CLOSE(HTML);
}


int main(){
   char result[1000] ={};
   cweb_stack_pointer = result;
   create_document("Mateus");
   
   char result2[1000] ={};
   cweb_stack_pointer = result2;
   create_document("Teste3");
   

   printf("%s\n",result2);
   printf("Ident level: %d\n",cweb_ident_level);
}