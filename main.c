//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CTextEngineMain.c"


void create_document(char *props,int data){
    $OPEN(HTML,props);
        OPEN(NULL);
            OPEN(H1);
                SPRINT("Hello World %d with %s props ",data,props);
            CLOSE(H1);
        CLOSE(NULL);
    CLOSE(HTML);
}




int main(){
   
   char result[1000] ={};
   ctext_get_stack_ownership(result);
   

   create_document("aaaa",20);

   
   
   printf("%s\n",result);
   printf("Ident level: %d\n",ctext_ident_level);
   ctext_release_stack_ownership();

   puts("----------------------------\n");

   char result2[1000] ={};
   ctext_get_stack_ownership(result2);
   create_document("bbb",40);
   printf("%s\n",result2);
   printf("Ident level: %d\n",ctext_ident_level);

   ctext_release_stack_ownership();
     
}