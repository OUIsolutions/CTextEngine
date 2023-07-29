
CTextArray * newCTextArray(){
    CTextArray  *self = (CTextArray*) malloc(sizeof (CTextArray));
    self->size = 0;
    self->stacks = (CTextStack**) malloc(0);
    return self;
}

void CTextArray_append(CTextArray *self,CTextStack *element){
    self->stacks =  (CTextStack**) realloc(
            self->stacks,
            (self->size+1)* sizeof (CTextStack*)
            );

    self->stacks[self->size] = element;
    self->size+=1;
}



void CTextArray_append_string(CTextArray *self,const char *element){
    CTextStack *new_element = newCTextStack_string(element);
    CTextArray_append(self,new_element);
}

CTextStack * CTextArray_join(CTextArray *self,const char *separator){
    CTextStack  *result  = newCTextStack_string_empty();
    for(int i = 0; i < self->size; i++){
        CTextStack_format(result,"%t%s",self->stacks[i],separator);
    }
    return result;
}


void  CTextArray_free(CTextArray *self){
    for(int i = 0; i < self->size; i++){
            CTextStack_free(self->stacks[i]);
    }
    free(self->stacks);
    free(self);
}

void CTextArray_represent(CTextArray *self){
    for(int i =0; i < self->size; i++){
        CTextStack_represent(self->stacks[i]);
    }
}