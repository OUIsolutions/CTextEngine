//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CTextEngineMain.c"


void create_document(char *props,int data){
    $OPEN(HTML,props);
        OPEN(BODY);
            OPEN(H1);
                SPRINT("Hello World %d",data);
            CLOSE(H1);
        CLOSE(BODY);
    CLOSE(HTML);
}




int main(){
   
   char result[1000] ={};
   ctext_stack_pointer = result;
   

   create_document("aaaa",20);
   create_document("bbbb",20);

   

   printf("%s\n",result);
   printf("Ident level: %d\n",ctext_ident_level);
}