//
// Created by jurandi on 18-04-2023.
//

char *cweb_stack_pointer;
#define CWEB_LINE_BREAKER "\n"
#define CWEB_SEPARATOR "   "
int cweb_ident_level = 0;


void private_cweb_engine_add(const char *element);

void private_cweb_engine_add_separator(int ident_level);





#define cweb_render(buffer, caller, ...) \
    do { \
        char *old_buffer = cweb_stack_pointer; \
        cweb_stack_pointer = buffer; \
        caller(__VA_ARGS__); \
        cweb_stack_pointer = old_buffer; \
    } while(0)


void $OPEN(const char *tag,const char *props);

void FRAGMENT(const char *text);

void OPEN(const char *tag);

void CLOSE(const char *tag);


