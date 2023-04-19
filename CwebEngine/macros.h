





#define cweb_render(buffer, caller, ...) \
    do { \
        char *old_buffer = cweb_stack_pointer; \
        cweb_stack_pointer = buffer; \
        caller(__VA_ARGS__); \
        cweb_stack_pointer = old_buffer; \
    } while(0)



