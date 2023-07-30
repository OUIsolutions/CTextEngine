
int CTextStack_typeof(struct CTextStack *self){
    if(self->size == 0){
        return CTEXT_STRING;
    }

    if(CTextStack_equal(self,"true") ||CTextStack_equal(self,"false") ){
        return CTEXT_BOOL;
    }

    double data;
    int result = sscanf(self->rendered_text,"%lf",&data);
    if(!result){
        return CTEXT_STRING;
    }
    if(CTextStack_index_of(self,".") == -1){
        return CTEXT_INTEGER;
    }
    return CTEXT_DOUBLE;


}



const char * CTextStack_typeof_in_str(struct CTextStack *self){
    int current_type = CTextStack_typeof(self);

    if(current_type == CTEXT_BOOL){
        return "bool";
    }

    if(current_type == CTEXT_STRING){
        return "string";
    }
    if(current_type == CTEXT_INTEGER){
        return "integer";
    }
    if(current_type == CTEXT_DOUBLE){
        return "double";
    }
}