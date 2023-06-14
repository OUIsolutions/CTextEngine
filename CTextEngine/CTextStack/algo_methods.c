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