
#define CText$Scope(element,tag,args,scope) \
        CTextStack_$open(element,tag,args,NULL);\
        scope\
        ctext_close(element,tag);

#define CtextArgs(...)__VA_ARGS__

#define CTextScope(element,tag,scope) \
        ctext_open(element,tag);\
        scope\
        ctext_close(element,tag);

/*

#define CTextScope(s,t) ctext_open(s, t); for(int i = 0; i < 1; ctext_close(s, t), ++i)

#define $OPEN(s,t, ...) s->$open(s, t, VA_ARGS); for(int i = 0; i < 1; s->close(s, t), ++i)
 */