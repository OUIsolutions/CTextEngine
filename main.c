//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine//CText.c"


struct CText * create_document(const char *props, int data){
    struct CText *vd = newCTextVirtualDom(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    /*
    vd->open(vd,NULL);

    vd->text(vd,"a1: ##");
    vd->text(vd,"a2: ");

        vd->open(vd,NULL);
            vd->text(vd,"b1: ##");
            vd->segment(vd);
            vd->text(vd,"b2: ##");

        vd->close(vd,NULL);
    vd->close(vd,NULL);
    */
    vd->open(vd,HTML);
        vd->open(vd,BODY);
            vd->segment(vd);
            vd->text(vd,"aaaaa");
        vd->close(vd,BODY);
    vd->close(vd,HTML);

    return vd;
}




int main(){
    struct CText *vd =  create_document("aaaa", 20);
    printf("%s",vd->rendered_text);
    vd->free(vd);

}