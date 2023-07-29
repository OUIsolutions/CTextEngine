
typedef struct CTextArrayModule{

    void (*append)(CTextArray *self,CTextStack *element);
    void (*append_string)(CTextArray *self,const char *element);
    CTextStack * (*join)(CTextArray *self,const char *separator);
    void  (*free)(CTextArray *self);

}CTextArrayModule;

CTextArrayModule newCTextArrayModule();