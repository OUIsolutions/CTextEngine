

struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"");
    self->rendered_text_alocation_size = 2;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);

    self->text = ctext_text;
    self->format = ctext_format;
    self->segment = ctext_segment;
    self->$open = ctext_$open;
    self->only$open =ctext_only$open;
    self->auto$close = ctext_auto$close;
    self->open = ctext_open;
    self->close = ctext_close;
    self->free =  ctext_free;
    return self;
}

void ctext_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}
