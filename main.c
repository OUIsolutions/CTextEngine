//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CTextEngineMain.c"


void create_document(char *props,int data,char *body){
    
    $OPEN(s,HTML,props);

        OPEN(s,BODY);
            OPEN(s,H1);
                SPRINT(s,"Hello World %d with %s props ",data,props);
            CLOSE(s,H1);
        CLOSE(s,BODY);
    
    CLOSE(s,HTML);
}




int main(){
   
   
     
}