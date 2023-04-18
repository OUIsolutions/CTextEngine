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
   create_document();
   char result[100];
   cweb_engine_render(result);
   printf("%s",result);
}