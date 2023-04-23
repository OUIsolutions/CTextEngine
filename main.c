//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine//CText.c"


struct CText * create_document(const char *props, int data){
    struct CText *vd = newCTextVirtualDom(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    $open(vd,HTML,"b=10");
        $open(vd,BODY,NULL);
            vd->text(vd,"text content here");
        vd->close(vd,BODY);
    vd->close(vd,HTML);

    return vd;
}




int main(){
    struct CText *vd =  create_document("aaaa", 20);
    printf("%s",vd->rendered_text);
    vd->free(vd);

}