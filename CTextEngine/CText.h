

#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "


struct CText{
    char *rendered_text;
    int rendered_text_alocation_size;
    char *line_breaker;
    char *separator;
    int ident_level;

    void (*text)(struct CText *self, const char *element);
    void (*cat_separator)(struct CText *self, bool break_line);


    void (*open_with_string_props)(struct CText *self, const char *tag, const char *props);
    void (*open)(struct CText *self, const char *tag);
    void (*close)(struct CText *self, const char *tag);


    void (*free)(struct CText *self);
    
};

struct CText *newCTextVirtualDom(const char *line_breaker, const char *separator);


void private_ctext_text(struct CText *self, const char *text);

void private_ctext_cat_separator(struct CText *self, bool break_line);

void private_ctext_open_with_string_props(struct CText *self, const char *tag, const char *props);


void private_ctext_open(struct CText *self, const char *tag);

void private_ctext_close(struct CText *self, const char *tag);


void private_ctext_free(struct CText *self);