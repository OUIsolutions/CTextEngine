
#ifndef CTEXT_LINE_BREAKER
    #define CTEXT_LINE_BREAKER "\n"
#endif
#ifndef CTEXT_SEPARATOR
    #define CTEXT_SEPARATOR "   "
#endif


struct CTextVirtualDom{
    char *acumulated_text;    
    int ident_level;
    char *line_breaker;
    char *separator;    


    void (*cat)(const char *element);
    void (*cat_separator)(int ident_level);
    void (*$open)(const char *tag,const char *props);
    void (*open)(const char *tag,const char *props);
    void (*text)(const char *text);
    void (*integer)(int number);
    void (*float)(float number);
    void (*boolean)(int boolean);
    void (*open)(const char *tag);
    void (*close)(const char *tag);
    

};

struct CTextVirtualDom newCTextVirtualDom();

void private_ctext_engine_cat(const char *element);

void private_ctext_engine_cat_separator(int ident_level);


void private_ctext_text(const char *text);

void private_ctext_integer(int number);

void private_ctext_float(float number);

void private_ctext_boolean(int boolean);

void private_ctext_$open(const char *tag,const char *props);

void private_ctext_open(const char *tag);

void private_ctext_close(const char *tag);


