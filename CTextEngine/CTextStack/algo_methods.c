
long private_CTextStack_transform_index(struct CTextStack *self, long value){
    long formated_value = value;

    if(formated_value >= (long)self->size){
        formated_value = (long)self->size;
    }

    if(formated_value  < 0){
        formated_value = (long)self->size + (formated_value +1);
    }
    if(formated_value <0){
        formated_value = 0;
    }
    return formated_value;
}


struct CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CTextStack_transform_index(self,starter);
    long formated_end = private_CTextStack_transform_index(self,end);

    if(formated_starter == formated_end){
        new_element->format(new_element,"%c",self->rendered_text[formated_starter]);
        return new_element;
    }

    for(long i =formated_starter; i < formated_end; i++){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }

    return new_element;

}

void CTextStack_self_substr(struct CTextStack *self, long starter, long end){
    CTextStack *new_stack = self->substr(self,starter,end);
    private_CTextStack_parse_ownership(self,new_stack);

}

struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long element_size = (long)strlen(element);
    for(long i = 0; i < self->size;i++){
        CTextStack  *possible_ocurrence  = self->substr(self,i,i+element_size);

        if(strcmp(possible_ocurrence->rendered_text,element)== 0){
            new_element->text(new_element,element_to_replace);
            i+=element_size -1;
        }

        else{
            new_element->format(new_element,"%c",self->rendered_text[i]);
        }

        possible_ocurrence->free(possible_ocurrence);

    }
    return new_element;
}

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace){
    CTextStack  *new_stack = self->replace(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


long CtextStack_index_of(struct  CTextStack *self,const char *element){
    long element_size = (long)strlen(element);
    for(int i = 0; i < self->size; i++){
        CTextStack  *possible_element = self->substr(self,i,i+element_size);
        if(strcmp(possible_element->rendered_text,element) == 0){
            possible_element->free(possible_element);
            return i;
        }
        possible_element->free(possible_element);

    }
    return -1;
}

struct CTextStack *CTextStack_reverse(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i = (long)self->size; i >= 0 ; i--){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;

}

void CTextStack_self_reverse(struct CTextStack *self){
    CTextStack *new_stack = self->reverse(self);
    private_CTextStack_parse_ownership(self,new_stack);
}



struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CTextStack_transform_index(self,starter);
    long formated_end = private_CTextStack_transform_index(self,end);

    for(int i =0; i < self->size; i ++){
        if(i >= formated_starter && i <= formated_end){
            continue;
        }
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end){
    CTextStack  *new_stack = self->pop(self, starter, end);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long converted_point = private_CTextStack_transform_index(self,point);
    for(long i = 0; i < converted_point; i++){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    new_element->text(new_element,element);
    for(long i = converted_point; i < self->size; i++){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}

void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element){
    CTextStack  *new_stack = self->insert_at(self, point,element);
    private_CTextStack_parse_ownership(self,new_stack);
}