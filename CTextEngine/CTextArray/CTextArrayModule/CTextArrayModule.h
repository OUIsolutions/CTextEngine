

typedef struct CTextArrayModule{

    CTextArray *(*split)(CTextStack *element, char *target);
    void (*append_raw)(CTextArray *self,CTextStack *element,int mode);
    void (*append_by_ownership)(CTextArray *self,CTextStack *element);
    void (*append_by_copy)(CTextArray *self,CTextStack *element);
    void (*append_by_reference)(CTextArray *self,CTextStack *element);


    CTextStack *(*get_by_ownership)(CTextArray *self, long position);
    CTextStack * (*get_by_copy)(CTextArray *self, long position);
    CTextStack * (*get_by_reference)(CTextArray *self, long position);
    CTextStack * (*join)(CTextArray *self, char *element);
    void (*free)(CTextArray *self);


}CTextArrayModule;

CTextArrayModule newCTextArrayModule();
