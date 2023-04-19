//
// Created by jurandi on 18-04-2023.
//

char *cweb_stack_pointer;
#define CWEB_LINE_BREAKER "\n"
#define CWEB_SEPARATOR "   "
int cweb_ident_level = 0;


void private_cweb_engine_cat(const char *element);

void private_cweb_engine_cat_separator(int ident_level);





void $OPEN(const char *tag,const char *props);

void TEXT(const char *text);

void INTEGER(int number);

void FLOAT(float number);

void BOOLEAN(int boolean);


void OPEN(const char *tag);

void CLOSE(const char *tag);


