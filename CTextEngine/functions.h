//
// Created by jurandi on 18-04-2023.
//

char *ctext_stack_pointer;
char *ctext_old_stack_pointer;
#ifndef CTEXT_LINE_BREAKER
    #define CTEXT_LINE_BREAKER "\n"
#endif
#ifndef CTEXT_SEPARATOR
    #define CTEXT_SEPARATOR "   "
#endif

int ctext_ident_level = 0;



void ctext_get_stack_ownership(char *stack_pointer);
void ctext_release_stack_ownership();

void private_ctext_engine_cat(const char *element);

void private_ctext_engine_cat_separator(int ident_level);





void $OPEN(const char *tag,const char *props);

void TEXT(const char *text);

void INTEGER(int number);

void FLOAT(float number);

void BOOLEAN(int boolean);


void OPEN(const char *tag);

void CLOSE(const char *tag);


