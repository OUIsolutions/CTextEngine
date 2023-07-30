
int CTextStack_typeof(struct CTextStack *self){
    if(self->size == 0){
        return CTEXT_NULL;
    }

    if(CTextStack_equal(self,"true") ||CTextStack_equal(self,"false") ){
        return CTEXT_BOOL;
    }

    double data;
    int result = sscanf(self->rendered_text,"%lf",data);
    if(!result){
        return CTEXT_STRING;
    }
    if(CTextStack_index_of(self,".") == -1){
        return CTEXT_INTEGER;
    }
    return CTEXT_BOOL;
}
