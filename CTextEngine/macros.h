
#define CTextScope(element,tag,scope,...) \
        CTextStack_$open(element,tag,__VA_ARGS__,NULL);\
        scope\
        ctext_close(element,tag);