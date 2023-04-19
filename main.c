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

void join_components(char *component1,char *component2){
    FRAGMENT(component1);
    FRAGMENT(component2);
}



int main(){
   char result[1000] ={};
   create_component(result,create_document,"teste");
  
   char result2[1000] ={};
   create_component(result2,create_document,"teste2");
  

   char result3[2000] ={};
   create_component(result3,join_components,result,result2);

   printf("%s\n",result3);
   printf("Ident level: %d\n",cweb_ident_level);
}