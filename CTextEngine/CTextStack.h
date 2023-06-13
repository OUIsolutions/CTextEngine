

#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "


struct CTextStack{
    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t rendered_text_size;
    
    char *line_breaker;
    char *separator;
    int ident_level;

    void (*text)(struct CTextStack *self, const char *element);

    void (*segment_text)(struct CTextStack *self, const char *element);
   
    void (*format)(struct CTextStack *self, const char *format, ...);

    void (*segment)(struct CTextStack *self);
   
    void (*segment_format)(struct CTextStack *self, const char *format, ...);

    void (*$open)(struct CTextStack *self, const char *tag, const char *format,...);
   
    void (*only$open)(struct CTextStack *self, const char *tag, const char *format,...);
   
    void (*auto$close)(struct CTextStack *self, const char *tag, const char *format,...);
   
    void (*open)(struct CTextStack *self, const char *tag);

    void (*close)(struct CTextStack *self, const char *tag);

    void (*free)(struct CTextStack *self);

    char * (*self_transform_in_string)(struct CTextStack *self);

    void (*restart)(struct CTextStack *self);

};

struct CTextStack *newCTextStack(const char *line_breaker, const char *separator);


void ctext_text(struct CTextStack *self, const char *text);

void private_ctext_text_double_size_if_reachs(struct CTextStack *self);

void ctext_segment_text(struct CTextStack *self, const char *text);

void private_ctext_segment_char(struct CTextStack *self, char t);

void ctext_segment(struct CTextStack *self);

void ctext_$open(struct CTextStack *self, const char *tag, const char *format,...);

void ctext_only$open(struct CTextStack *self, const char *tag, const char *format,...);

void ctext_auto$close(struct CTextStack *self, const char *tag, const char *format,...);


void ctext_format(struct CTextStack *self, const char *format, ...);

void ctext_segment_format(struct CTextStack *self, const char *format, ...);

void ctext_open(struct CTextStack *self, const char *tag);


void ctext_close(struct CTextStack *self, const char *tag);

void ctext_free(struct CTextStack *self);

char * ctext_self_transform_in_string(struct CTextStack *self);


void ctext_restart(struct CTextStack *self);