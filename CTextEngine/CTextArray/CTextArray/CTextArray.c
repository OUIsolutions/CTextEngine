
CTextArray * newCTextArray(){
    CTextArray  *self = (CTextArray*) malloc(sizeof (CTextArray));
    self->size = 0;
    self->ownership = (bool*)malloc(0);
    self->stacks = (CTextStack**) malloc(0);
    return self;
}

void CTextArray_append(CTextArray *self,CTextStack *element,int mode){
    self->stacks =  (CTextStack**) realloc(
            self->stacks,
            (self->size+1)* sizeof (CTextStack*)
            );

    self->ownership = (bool*) realloc(
            self->ownership,
            (self->size+1) *sizeof (bool*)
            );

    if(mode == CTEXT_BY_VALUE){
        self->stacks[self->size] = CTextStack_clone(element);
        self->ownership[self->size] = true;
    }
    if(mode == CTEXT_BY_REFERENCE){
        self->stacks[self->size] = element;
        self->ownership[self->size] = false;
    }
    if(mode == CTEXT_BY_OWNERSHIP){
        self->stacks[self->size] = element;
        self->ownership[self->size] = true;
    }

}


void CTextArray_get(CTextArray *self,int point,int mode){
    
}

void CTextArray_append_string(CTextArray *self,char *element);

CTextStack * CTextArray_join(CTextArray *self,char *separator);


void  CTextArray_free(CTextArray *self);
