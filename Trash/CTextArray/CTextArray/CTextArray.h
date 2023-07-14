

typedef struct CTextArray{

    CTextStack **elements;
    bool *ownership;
    long size;

}CTextArray;

CTextArray * newCTextArray();
CTextArray * CTextArray_split(CTextStack *element, char *target);
void CTextArray_append_raw(CTextArray *self,CTextStack *element,int mode);

void CTextArray_append_assuming_ownership(CTextArray *self, CTextStack *element);
void CTextArray_append_string(CTextArray *self,const char *element);
void CTextArray_append_by_copy(CTextArray *self,CTextStack *element);
void CTextArray_append_by_reference(CTextArray *self,CTextStack *element);

CTextStack * CTextArray_get_by_ownership(CTextArray *self, long position);
CTextStack * CTextArray_get_by_copy(CTextArray *self, long position);
CTextStack * CTextArray_get_by_reference(CTextArray *self, long position);

CTextStack * CTextArray_join(CTextArray *self, char *element);

void CTextArray_represent(CTextArray *self);

void CTextArray_free(CTextArray *self);
