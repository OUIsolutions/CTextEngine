
#define  CTEXT_BY_VALUE 1
#define  CTEXT_BY_OWNERSHIP 2
#define  CTEXT_BY_REFERENCE 3


typedef struct CTextArray{

    CTextStack **stacks;
    bool *ownership;
    long size;


}CTextArray;

CTextArray * newCTextArray();

void CTextArray_append(CTextArray *self,CTextStack *element,int mode);

CTextStack *CTextArray_get(CTextArray *self,long point,int mode);

void CTextArray_append_string(CTextArray *self,char *element);

CTextStack * CTextArray_join(CTextArray *self,char *separator);


void  CTextArray_free(CTextArray *self);
