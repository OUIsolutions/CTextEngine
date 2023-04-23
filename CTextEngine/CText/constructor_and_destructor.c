

struct CText * newCTextVirtualDom(const char *line_breaker, const char *separator){
    struct CText *self = (struct CText*)malloc(sizeof(struct CText));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"");
    self->rendered_text_alocation_size = 2;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);

    self->text = private_ctext_text;
    self->cat_separator = private_ctext_cat_separator;
    self->open_with_props = private_ctext_open_with_props;
    self->open = private_ctext_open;
    self->open_empty = private_ctext_open_empty;
    self->close = private_ctext_close;
    self->free =  private_ctext_free;
    return self;
}

void private_ctext_free(struct CText *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}
