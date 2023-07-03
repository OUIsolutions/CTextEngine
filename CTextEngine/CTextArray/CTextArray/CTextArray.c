

CTextArray * newCTextArray(){
    CTextArray *self =(CTextArray*) malloc(sizeof (CTextArray));
    self->elements = malloc(0);
    self->ownership = malloc(0);
    self->size = 0;
    return self;
}
//CTextArray * CTextArray_split(CTextStack *element, char *target);

void CTextArray_append_by_ownership(CTextArray *self,CTextStack *element){
    
}
void CTextArray_append_by_copy(CTextArray *self,CTextStack *element);
void CTextArray_append_by_reference(CTextArray *self,CTextStack *element);

CTextStack * CTextArray_get_by_ownership(CTextArray *self, int position);
CTextStack * CTextArray_get_by_copy(CTextArray *self, int position);
CTextStack * CTextArray_get_by_reference(CTextArray *self, int position);

CTextStack * CTextArray_join(CTextArray *self, char *element);
