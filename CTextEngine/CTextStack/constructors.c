//
// Created by jurandi on 14-06-2023.
//
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
    self->clone = CTextStack_clone;
    self->represent = CTextStack_represent;
    self->self_transform_in_string_and_self_clear = CTextStack_self_transform_in_string_and_self_clear;
    self->restart = CTextStack_restart;
    self->substr = CTextStack_substr;
    self->self_substr =CTextStack_self_substr;

    self->pop = CTextStack_pop;
    self->self_pop =CTextStack_self_pop;

    self->replace = CTextStack_replace;
    self->self_replace = CTextStack_self_replace;

    self->insert_at = CTextStack_insert_at;
    self->self_insert_at  = CTextStack_self_insert_at;


    self->index_of = CtextStack_index_of;
    self->index_of_char = CtextStack_index_of_char;
    self->reverse = CTextStack_reverse;

    self->trim = CTextStack_trim;
    self->self_trim = CTextStack_self_trim;

    self->self_reverse = CTextStack_self_reverse;

    return self;
}

struct CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        self->format(self,starter);
    }
    return self;
}

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter){
    CTextStack *self = newCTextStack("","");
    free(self->rendered_text);
    self->rendered_text = (char*)starter;
    self->size = strlen(starter);
    self->rendered_text_alocation_size = self->size;
    return self;
}
struct CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}