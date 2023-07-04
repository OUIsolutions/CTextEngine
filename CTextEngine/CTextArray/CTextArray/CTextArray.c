

CTextArray * newCTextArray(){
    CTextArray *self =(CTextArray*) malloc(sizeof (CTextArray));
    self->elements = malloc(0);
    self->ownership = malloc(0);
    self->size = 0;
    return self;
}
CTextArray * CTextArray_split(CTextStack *element, char *target){

}

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

CTextStack * CTextArray_get_by_ownership(CTextArray *self, long position){
    long new_position = private_CText_transform_index(self->size,position);
    CTextStack  *element = self->elements[new_position];
    self->ownership[position] = false;
    return element;
}

CTextStack * CTextArray_get_by_copy(CTextArray *self, long position){
    long new_position = private_CText_transform_index(self->size,position);
    CTextStack  *element = self->elements[new_position];
    CTextStack  *new_version = CTextStack_clone(element);
    return new_version;
}

CTextStack * CTextArray_get_by_reference(CTextArray *self, long position){
    long new_position = private_CText_transform_index(self->size,position);
    CTextStack  *element = self->elements[new_position];
    return element;
}

CTextStack * CTextArray_join(CTextArray *self, char *element){
    CTextStack  *stack = newCTextStack_string_empty();
    for(long i = 0; i < self->size; i++){
        CTextStack_format(stack,"%t",self->elements[i]);
        if(element){
            CTextStack_format(stack,"%s",element);
        }
    }
}


void CTextArray_free(CTextArray *self){
    for(long i = 0 ; i < self->size; i++){
        bool owner = self->ownership[i];

        if(owner){
            CTextStack_free(self->elements[i]);
        }
    }

    free(self->ownership);
    free(self->elements);
    free(self);

}