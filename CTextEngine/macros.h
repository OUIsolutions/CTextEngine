
#define CText$Scope(element,tag,args,scope) \
        CTextStack_$open(element,tag,args,NULL);\
        scope\
        ctext_close(element,tag);

#define CtextArgs(...)__VA_ARGS__

#define CTextScope(element,tag,scope) \
        ctext_open(element,tag);\
        scope\
        ctext_close(element,tag);