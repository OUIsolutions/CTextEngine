

#define CTextScope(...)\
while(privateCTextStack_smart_scope(__VA_ARGS__))\


#define CText$Scope(...) \
while(privateCTextStack_$smart_scope(__VA_ARGS__))\
