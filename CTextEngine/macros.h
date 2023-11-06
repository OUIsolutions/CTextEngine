
#define CTextScope(s,t)\
ctext_open(s, t);\
for(int i = 0; i < 1; ctext_close(s, t), ++i)

#define CText$Scope(s,t, ...)\
CTextStack_$open(s,t,__VA_ARGS__);\
for(int i = 0; i < 1; ctext_close(s, t), ++i)
