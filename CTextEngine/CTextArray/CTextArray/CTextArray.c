

CTextArray * newCTextArray(){
    CTextArray *self =(CTextArray*) malloc(sizeof (CTextArray));
    self->elements = malloc(0);
    self->ownership = malloc(0);
    self->size = 0;
    return self;
}
//CTextArray * CTextArray_split(CTextStack *element, char *target);

void CTextArray_append_raw(CTextArray *self,CTextStack *element,int mode){
    self->elements = (CTextStack**)realloc(self->elements,(self->size +1)* sizeof (CTextStack**));
    self->ownership= (bool*) realloc(self->ownership,(self->size+1) *sizeof (bool));

    if(mode == CTEXT_BY_COPY ){
        self->elements[self->size] = CTextStack_clone(element);
    }
    else{
        self->elements[self->size] = element;
    }

    self->ownership[self->size] = false;
    if(mode == CTEXT_BY_COPY || mode == CTEXT_BY_OWNESHIP){
        self->ownership[self->size] = true;
    }
    self->size+=1;
}

void CTextArray_append_by_ownership(CTextArray *self,CTextStack *element){
    CTextArray_append_raw(self,element,CTEXT_BY_OWNESHIP);
}

void CTextArray_append_by_copy(CTextArray *self,CTextStack *element){
    CTextArray_append_raw(self,element,CTEXT_BY_COPY);
}

void CTextArray_append_by_reference(CTextArray *self,CTextStack *element){
    CTextArray_append_raw(self,element,CTEXT_BY_REFERENCE);
}

CTextStack * CTextArray_get_by_ownership(CTextArray *self, int position){
    CTextStack  *element = self->elements[position];
}

CTextStack * CTextArray_get_by_copy(CTextArray *self, int position);

CTextStack * CTextArray_get_by_reference(CTextArray *self, int position);

CTextStack * CTextArray_join(CTextArray *self, char *element);
