

struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);
    self->text = CTextStack_text;
    self->segment_text = CTextStack_segment_text;
    self->format = CTextStack_format;
    self->segment = CTextStack_segment;
    self->segment_format = CTextStack_segment_format;
    self->$open = CTextStack_$open;
    self->only$open =CTextStack_only$open;
    self->auto$close = CTextStack_auto$close;
    self->open = ctext_open;
    self->close = ctext_close;
    self->free =  CTextStack_free;
    self->self_transform_in_string = CTextStack_self_transform_in_string;
    self->restart = CTextStack_restart;
    self->substr = CTextStack_substr;
    self->self_substr =CTextStack_self_substr;
    return self;
}


struct CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        self->format(self,starter);
    }
    return self;
}

struct CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}


void CTextStack_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}

char * CTextStack_self_transform_in_string(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    char *result = self->rendered_text;
    free(self);
    return result;
}

void CTextStack_restart(struct CTextStack *self){
    free(self->rendered_text);
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
}