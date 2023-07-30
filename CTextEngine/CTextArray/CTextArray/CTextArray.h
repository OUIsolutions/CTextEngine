

typedef struct CTextArray{

    CTextStack **stacks;
    long size;


}CTextArray;

CTextArray * newCTextArray();


void CTextArray_append(CTextArray *self,CTextStack *element);


void CTextArray_append_string(CTextArray *self,const char *element);

CTextStack * CTextArray_join(CTextArray *self,const char *separator);

CTextArray *CTextArray_split(const char *element,const char *target);

void  CTextArray_free(CTextArray *self);

void CTextArray_represent(CTextArray *self);
