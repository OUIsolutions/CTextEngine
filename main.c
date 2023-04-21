//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine/CTextEngineMain.c"


void create_document(char *props,int data,char *body){
    
    s->$OPEN(s,HTML,props);
        s->OPEN(s,body);
            s->OPEN(s,H1);
                s->SPRINT(s,"Hello World %d with %s props ",data,props);
            s->CLOSE(s,H1);
       s->CLOSE(s,body);
    s->CLOSE(s,HTML);
}




int main(){
   
   
     
}