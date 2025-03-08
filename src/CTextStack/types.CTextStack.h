//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.macros.h"
//silver_chain_scope_end

#ifndef PRIVATE_CTEXT_STACK_TYPE_H
#define PRIVATE_CTEXT_STACK_TYPE_H
typedef struct CTextStack{

    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t size;

    char *line_breaker;
    char *separator;
    int ident_level;

}CTextStack;
#endif
