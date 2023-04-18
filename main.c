//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CwebEngine/CwebEngineMain.c"


void create_document(){
    $OPEN(HTML,"aaaa");
        $OPEN(BODY,NULL);
            $OPEN(H1,NULL);
                $FRAGMENT("Hello World");
            $CLOSE(H1,NULL);
        $CLOSE(BODY,NULL);
    $CLOSE(HTML,NULL);
}


int main(){
   char result[1000] ={};
   cweb_stack_pointer = result;
   create_document();
   

   printf("%s\n",result);
}