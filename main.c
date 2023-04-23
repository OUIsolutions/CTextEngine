//
// Created by jurandi on 18-04-2023.
//
#include <stdio.h>

#include "CTextEngine//CText.c"


#ifdef __cplusplus

    #define SET_MAIN_STACK(self) \
    auto OPEN = [self](const char *tag){\
        self->open(self,tag);\
    };   \
    auto CLOSE = [self](const char *tag){\
        self->close(self,tag);\
    };   \
    \
    auto text = [self](const char *text){\
        self->text(self,text);\
    };   \
    auto endLine = [self](){\
        self->segment(self);\
    };   \

#else 
#define SET_MAIN_STACK(self) \
   \
   void OPEN(const char *tag){\
        self->open(self,tag);\
    }   \
    void CLOSE(const char *tag){\
        self->close(self,tag);\
    }   \
    \
    void text(const char *text){\
        self->text(self,text);\
    }   \
    void endLine(){\
        self->segment(self);\
    }   \

#endif







struct CText *vd;
SET_MAIN_STACK(vd);


void create_html(const char *props, int data){

    OPEN(HTML);
        OPEN(HEAD);
            if(data == 1)

                OPEN(TITLE);
                    text("data is 1");
                CLOSE(TITLE);

        CLOSE(HEAD);
        OPEN(BODY);
                OPEN(P);
                    text("data is 1");
                CLOSE(P);

        CLOSE(BODY);

    return vd;
}



int main(){
    vd = newCTextStack(CTEXT_LINE_BREAKER,CTEXT_SEPARATOR);
    create_html("aaaaaaa",20);
    printf("%s",vd->rendered_text);
    vd->free(vd);

}