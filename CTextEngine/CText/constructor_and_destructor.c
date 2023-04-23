

struct CText * newCTextStack(const char *line_breaker, const char *separator){
    struct CText *self = (struct CText*)malloc(sizeof(struct CText));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"");
    self->rendered_text_alocation_size = 2;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);

    self->text = ctext_text;
    self->segment = ctext_segment;
    self->open_with_string_props = ctext_open_with_string_props;
    self->open = ctext_open;
    self->close = ctext_close;
    self->free =  ctext_free;
    return self;
}

void ctext_free(struct CText *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}
