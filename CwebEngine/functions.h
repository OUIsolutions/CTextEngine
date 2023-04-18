//
// Created by jurandi on 18-04-2023.
//

#ifndef CWEBENGINE_STACK_SIZE 
#define CWEBENGINE_STACK_SIZE 1000000
#endif

char cweb_engine_stack[CWEBENGINE_STACK_SIZE];

void FRAGMENT(const char *text);

void OPEN(const char *tag,const char *props);

void CLOSE(const char *tag,const char *props);

void cweb_engine_render(const char *html);
void cweb_engine_clear_stack();


