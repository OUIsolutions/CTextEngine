

#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "


struct CTextStack{
    char *rendered_text;
    int rendered_text_alocation_size;
    char *line_breaker;
    char *separator;
    int ident_level;

    void (*text)(struct CTextStack *self, const char *element);
    void (*format)(struct CTextStack *self, const char *format, ...);

    void (*segment)(struct CTextStack *self);


    void (*$open)(struct CTextStack *self, const char *tag, const char *format,...);
    void (*open)(struct CTextStack *self, const char *tag);
    void (*close)(struct CTextStack *self, const char *tag);


    void (*free)(struct CTextStack *self);
    
};

struct CTextStack *newCTextStack(const char *line_breaker, const char *separator);


void ctext_text(struct CTextStack *self, const char *text);

void ctext_segment(struct CTextStack *self);

void ctext_$open(struct CTextStack *self, const char *tag, const char *format,...);

void ctext_format(struct CTextStack *self, const char *format, ...);

void ctext_open(struct CTextStack *self, const char *tag);

void ctext_close(struct CTextStack *self, const char *tag);


void ctext_free(struct CTextStack *self);
