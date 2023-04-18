//
// Created by jurandi on 18-04-2023.
//

char *cweb_stack_pointer;

void private_cweb_engine_add(const char *element);

void $FRAGMENT(const char *text);

void $OPEN(const char *tag,const char *props);

void $CLOSE(const char *tag,const char *props);

