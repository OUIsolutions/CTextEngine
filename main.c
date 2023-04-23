//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine//CText.c"
#define test_yaml
//#define test_html



#define SET_MAIN_STACK(self) \
   \
   void OPEN(const char *tag){\
        self->open(self,tag);\
    }   \
    void CLOSE(const char *tag){\
        self->close(self,tag);\
    }   \
    void text(const char *text){\
        self->text(self,text);\
    }   \
    void endLine(){\
        self->segment(self);\
    }   \




struct CText * create_document(const char *props, int data){
    struct CText *vd = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    SET_MAIN_STACK(vd)

    OPEN(NULL);
        text("x1: ##");
        endLine();
        text("x2:");
            OPEN(NULL);
                text("b1: ##");
                endLine();
                text("b2: ##");
            CLOSE(NULL);
        text("x3: ##");
    CLOSE(NULL);

    return vd;
}




int main(){
    struct CText *vd =  create_document("aaaa", 20);
    printf("%s",vd->rendered_text);
    vd->free(vd);

}