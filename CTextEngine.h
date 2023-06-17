/*
MIT License

Copyright (c) 2023 OUI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CTEXTENGINE_H
#define CTEXTENGINE_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
//
// Created by jurandi on 18-04-2023.
//
#define CTEXT_HTML "html"
#define CTEXT_BODY "body"
#define CTEXT_DIV "div"
#define CTEXT_H1 "h1"
#define CTEXT_H2 "h2"
#define CTEXT_H3 "h3"
#define CTEXT_H4 "h4"
#define CTEXT_H5 "h5"
#define CTEXT_H6 "h6"
#define CTEXT_P "p"
#define CTEXT_SPAN "span"
#define CTEXT_A "a"
#define CTEXT_IMG "img"
#define CTEXT_INPUT "input"
#define CTEXT_BUTTON "button"
#define CTEXT_TABLE "table"
#define CTEXT_TR "tr"
#define CTEXT_TD "td"
#define TH "th"
#define CTEXT_THEAD "thead"
#define CTEXT_TBODY "tbody"
#define CTEXT_TFOOT "tfoot"
#define CTEXT_UL "ul"
#define CTEXT_LI "li"
#define CTEXT_OL "ol"
#define CTEXT_FORM "form"
#define CTEXT_LABEL "label"
#define CTEXT_SELECT "select"
#define CTEXT_OPTION "option"
#define CTEXT_TEXTAREA "textarea"
#define CTEXT_SCRIPT "script"
#define CTEXT_STYLE "style"
#define CTEXT_META "meta"
#define CTEXT_LINK "link"
#define CTEXT_HEAD "head"
#define CTEXT_BASE "base"
#define CTEXT_BR "br"
#define CTEXT_HR "hr"
#define CTEXT_TITLE "title"
#define CTEXT_IFRAME "iframe"
#define CTEXT_NAV "nav"
#define CTEXT_HEADER "header"
#define CTEXT_FOOTER "footer"
#define CTEXT_SECTION "section"
#define CTEXT_ARTICLE "article"
#define CTEXT_ASIDE "aside"
#define CTEXT_DETAILS "details"
#define CTEXT_SUMMARY "summary"
#define CTEXT_DIALOG "dialog"
#define MENU "menu"
#define MENUITEM "menuitem"
#define CTEXT_MAIN "main"
#define CTEXT_CANVAS "canvas"
#define CTEXT_AUDIO "audio"
#define CTEXT_VIDEO "video"
#define CTEXT_SOURCE "source"
#define CTEXT_TRACK "track"
#define CTEXT_EMBED "embed"
#define CTEXT_PARAM "param"
    





#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "


typedef struct CTextStack{

    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t size;
    
    char *line_breaker;
    char *separator;
    int ident_level;

    //admnistrative methods
    void (*free)(struct CTextStack *self);
    struct CTextStack *(*clone)(struct CTextStack *self);
    void (*represent)(struct CTextStack *self);
    char *(*self_transform_in_string_and_self_clear)(struct CTextStack *self);
    void (*restart)(struct CTextStack *self);

    //render methods
    void (*text)(struct CTextStack *self, const char *element);

    void (*segment_text)(struct CTextStack *self, const char *element);

    void (*format)(struct CTextStack *self, const char *format, ...);

    void (*segment)(struct CTextStack *self);
   
    void (*segment_format)(struct CTextStack *self, const char *format, ...);

    void (*$open)(struct CTextStack *self, const char *tag, const char *format,...);
   
    void (*only$open)(struct CTextStack *self, const char *tag, const char *format,...);
   
    void (*auto$close)(struct CTextStack *self, const char *tag, const char *format,...);
   
    void (*open)(struct CTextStack *self, const char *tag);

    void (*close)(struct CTextStack *self, const char *tag);


    //algorithm methods
    struct CTextStack * (*substr)(struct CTextStack *self, long starter, long end);
    void  (*self_substr)(struct CTextStack *self, long starter, long end);


    struct CTextStack *(*pop)(struct CTextStack *self, long starter, long end);
    void(*self_pop)(struct CTextStack *self, long starter, long end);


    struct CTextStack *(*insert_at)(struct CTextStack *self,long point, const char *element);
    void (*self_insert_at)(struct CTextStack *self,long point, const char *element);

    struct CTextStack *(*replace)(struct CTextStack *self,const char *element, const char *element_to_replace);
    void (*self_replace)(struct CTextStack *self,const char *element, const char *element_to_replace);


    struct CTextStack * (*reverse)(struct CTextStack *self);
    void(*self_reverse)(struct CTextStack *self);

    struct CTextStack * (*trim)(struct CTextStack *self);
    void(*self_trim)(struct CTextStack *self);

    long (*index_of)(struct CTextStack *self, const char *element);
    long (*index_of_char)(struct CTextStack *self, char element);
}CTextStack;

struct CTextStack *newCTextStack(const char *line_breaker, const char *separator);


struct CTextStack *newCTextStack_string(const char *starter);

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter);

struct CTextStack *newCTextStack_string_empty();


void CTextStack_text(struct CTextStack *self, const char *text);


void private_ctext_text_double_size_if_reachs(struct CTextStack *self);


void CTextStack_segment_text(struct CTextStack *self, const char *text);


void CTextStack_segment(struct CTextStack *self);


void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_format(struct CTextStack *self, const char *format, ...);


void CTextStack_segment_format(struct CTextStack *self, const char *format, ...);


void ctext_open(struct CTextStack *self, const char *tag);


void ctext_close(struct CTextStack *self, const char *tag);

void CTextStack_represent(struct CTextStack *self);
void CTextStack_free(struct CTextStack *self);


struct CTextStack * CTextStack_clone(struct CTextStack *self);


char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self);

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_string);


void CTextStack_restart(struct CTextStack *self);


//algorithm methods
long private_CTextStack_transform_index(struct CTextStack *self, long value);

struct CTextStack *CTextStack_substr(struct CTextStack *self, long starter, long end);
void CTextStack_self_substr(struct CTextStack *self, long starter, long end);


struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end);
void  CTextStack_self_pop(struct CTextStack *self, long starter, long end);


struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace);
void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace);


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element);
void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element);


long CtextStack_index_of_char(struct  CTextStack *self,char element);
long CtextStack_index_of(struct  CTextStack *self,const char *element);



struct CTextStack *CTextStack_trim(struct CTextStack *self);
void CTextStack_self_trim(struct CTextStack *self);


struct CTextStack *CTextStack_reverse(struct CTextStack *self);
void CTextStack_self_reverse(struct CTextStack *self);



void private_ctext_generate_formated_text(
    struct CTextStack *stack,
    const char *format,
    va_list argptr
    );
//
// Created by jurandi on 14-06-2023.
//
struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);
    self->text = CTextStack_text;
    self->segment_text = CTextStack_segment_text;
    self->format = CTextStack_format;
    self->segment = CTextStack_segment;
    self->segment_format = CTextStack_segment_format;
    self->$open = CTextStack_$open;
    self->only$open =CTextStack_only$open;
    self->auto$close = CTextStack_auto$close;
    self->open = ctext_open;
    self->close = ctext_close;
    self->free =  CTextStack_free;
    self->clone = CTextStack_clone;
    self->represent = CTextStack_represent;
    self->self_transform_in_string_and_self_clear = CTextStack_self_transform_in_string_and_self_clear;
    self->restart = CTextStack_restart;
    self->substr = CTextStack_substr;
    self->self_substr =CTextStack_self_substr;

    self->pop = CTextStack_pop;
    self->self_pop =CTextStack_self_pop;

    self->replace = CTextStack_replace;
    self->self_replace = CTextStack_self_replace;

    self->insert_at = CTextStack_insert_at;
    self->self_insert_at  = CTextStack_self_insert_at;


    self->index_of = CtextStack_index_of;
    self->index_of_char = CtextStack_index_of_char;
    self->reverse = CTextStack_reverse;

    self->trim = CTextStack_trim;
    self->self_trim = CTextStack_self_trim;

    self->self_reverse = CTextStack_self_reverse;

    return self;
}

struct CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        self->format(self,starter);
    }
    return self;
}

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter){
    CTextStack *self = newCTextStack("","");
    free(self->rendered_text);
    self->rendered_text = (char*)starter;
    self->size = strlen(starter);
    self->rendered_text_alocation_size = self->size;
    return self;
}
struct CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}






char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    char *result = self->rendered_text;
    free(self);
    return result;
}
void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack){

    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);

    self->rendered_text_alocation_size = new_stack->rendered_text_alocation_size;
    self->size = new_stack->size;
    self->ident_level = new_stack->ident_level;


    self->line_breaker = new_stack->line_breaker;
    self->separator = new_stack->separator;
    self->rendered_text = new_stack->rendered_text;
    free(new_stack);

}
void CTextStack_restart(struct CTextStack *self){
    free(self->rendered_text);
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
}

void CTextStack_represent(struct CTextStack *self){
    printf("%s\n",self->rendered_text);
}


void CTextStack_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}

struct CTextStack * CTextStack_clone(struct CTextStack *self){
    CTextStack *new_stack = newCTextStack(self->line_breaker,self->separator);
    new_stack->ident_level = self->ident_level;
    new_stack->text(new_stack,self->rendered_text);
    return new_stack;
}

long private_CTextStack_transform_index(struct CTextStack *self, long value){
    long formated_value = value;

    if(formated_value >= (long)self->size){
        formated_value = (long)self->size;
    }

    if(formated_value  < 0){
        formated_value = (long)self->size + (formated_value +1);
    }
    if(formated_value <0){
        formated_value = 0;
    }
    return formated_value;
}


struct CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CTextStack_transform_index(self,starter);
    long formated_end = private_CTextStack_transform_index(self,end);

    if(formated_starter == formated_end){
        new_element->format(new_element,"%c",self->rendered_text[formated_starter]);
        return new_element;
    }

    for(long i =formated_starter; i < formated_end; i++){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }

    return new_element;

}

void CTextStack_self_substr(struct CTextStack *self, long starter, long end){
    CTextStack *new_stack = self->substr(self,starter,end);
    private_CTextStack_parse_ownership(self,new_stack);

}

struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long element_size = (long)strlen(element);
    for(long i = 0; i < self->size;i++){
        CTextStack  *possible_ocurrence  = self->substr(self,i,i+element_size);

        if(strcmp(possible_ocurrence->rendered_text,element)== 0){
            new_element->text(new_element,element_to_replace);
            i+=element_size -1;
        }

        else{
            new_element->format(new_element,"%c",self->rendered_text[i]);
        }

        possible_ocurrence->free(possible_ocurrence);

    }
    return new_element;
}

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace){
    CTextStack  *new_stack = self->replace(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


long CtextStack_index_of(struct  CTextStack *self,const char *element){
    long element_size = (long)strlen(element);
    for(int i = 0; i < self->size; i++){
        CTextStack  *possible_element = self->substr(self,i,i+element_size);
        if(strcmp(possible_element->rendered_text,element) == 0){
            possible_element->free(possible_element);
            return i;
        }
        possible_element->free(possible_element);

    }
    return -1;
}

long CtextStack_index_of_char(struct  CTextStack *self,char element){
    for(int i = 0; i < self->size; i++) {
        if(self->rendered_text[i] == element){
            return i;
        }
    }
    return -1;
}

struct CTextStack *CTextStack_reverse(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i = (long)self->size; i >= 0 ; i--){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;

}

void CTextStack_self_reverse(struct CTextStack *self){
    CTextStack *new_stack = self->reverse(self);
    private_CTextStack_parse_ownership(self,new_stack);
}



struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CTextStack_transform_index(self,starter);
    long formated_end = private_CTextStack_transform_index(self,end);

    for(int i =0; i < self->size; i ++){
        if(i >= formated_starter && i <= formated_end){
            continue;
        }
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end){
    CTextStack  *new_stack = self->pop(self, starter, end);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long converted_point = private_CTextStack_transform_index(self,point);
    for(long i = 0; i < converted_point; i++){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    new_element->text(new_element,element);
    for(long i = converted_point; i < self->size; i++){
        new_element->format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}

void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element){
    CTextStack  *new_stack = self->insert_at(self, point,element);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_trim(struct CTextStack *self){

    CTextStack  *invalid_elements = newCTextStack_string("\t\r\n ");
    long start_point = 0;
    for(int i = 0; i < self->size; i ++){
        char current_char =self->rendered_text[i];
        long invalid_point = invalid_elements->index_of_char(invalid_elements,current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            start_point = i;
            break;
        }
    }
    long end_point = -1;
    for(long i = (long)self->size -1; i >= 0; i--){

        char current_char =self->rendered_text[i];
        long invalid_point = invalid_elements->index_of_char(invalid_elements,current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            end_point = i+1;
            break;
        }
    }
    invalid_elements->free(invalid_elements);
    return self->substr(self,start_point,end_point);

}

void CTextStack_self_trim(struct CTextStack *self){
    CTextStack  *new_stack = self->trim(self);
    private_CTextStack_parse_ownership(self,new_stack);
}
void private_ctext_text_double_size_if_reachs(struct CTextStack *self){

    while(self->size >= (self->rendered_text_alocation_size - 2)){
        self->rendered_text_alocation_size  =  (self->rendered_text_alocation_size  * 2)+2;
        self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
        ));
    }
}

void CTextStack_text(struct CTextStack *self, const char *text){

    if (!text || !text[0]) {
        // Tratar caso de ponteiro nulo ou string vazia
        return;
    }

    size_t text_size = strlen(text);
    
    self->size += text_size;
    private_ctext_text_double_size_if_reachs(self);
    
    memcpy(
            self->rendered_text + self->size - text_size,
        text,
        text_size 
    );
    self->rendered_text[self->size] = '\0';
}



void CTextStack_segment_text(struct CTextStack *self, const char *text){
    self->segment(self);
    self->text(self,text);
}


void CTextStack_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}

void CTextStack_segment_format(struct CTextStack *self, const char *format, ...){
    self->segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}


void CTextStack_segment(struct CTextStack *self){

    self->text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        self->text(self,self->separator);

    }


}

void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    self->format(self, "%c",'<');
    self->text(self,tag);


    if(format!=NULL){
        self->format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    self->format(self, "%c",'>');


    self->ident_level += 1;
}

void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    self->format(self, "%c",'<');

    self->text(self,tag);


    if(format!=NULL){
        self->format(self, "%c",' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    self->format(self, "%c",'>');


}

void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...){
    self->segment(self);
    self->format(self, "%c",'<');

    self->text(self,tag);


    if(format!=NULL){
        self->format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    self->text(self,"/>");

}

void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }

    self->$open(self, tag, NULL);
}




void ctext_close(struct CTextStack *self, const char *tag){

    if(tag==NULL){
        self->ident_level -= 1;

        return;
    }
    self->ident_level -= 1;
    self->segment(self);


    self->text(self,"</");
    self->text(self,tag);
    self->format(self, "%c",'>');

}



void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    long  text_size = strlen(format);

    int i;
    for(i =0;i < text_size -1 ;i++){

        char single_test[3] = {format[i],format[i+1],'\0'};
        char double_test[4] = {0};


        if(i < text_size -2){
            strcpy(double_test,single_test);
            double_test[2] = format[i+2];
            double_test[3] = '\0';

        }

        if(strcmp(single_test,"%d") == 0) {
            char result[10];
            sprintf(result,"%d", va_arg(argptr,int));
            stack->text(stack,result);
            i+=1;
            continue;
        }

        if(strcmp(single_test,"%f") == 0) {
            char result[10];
            sprintf(result,"%f", va_arg(argptr,double ));
            stack->text(stack,result);
            i+=1;
            continue;
        }

        else if(strcmp(single_test,"%c") == 0){
            char result = va_arg(argptr,int);
            char element[2] = {result,'\0'};
            stack->text(stack,element);
            i+=1;
            continue;
        }


        else if(strcmp(single_test,"%b") == 0){
            bool value = va_arg(argptr,int);
            if(value){
                stack->text(stack,"true");
            }else{
                stack->text(stack,"false");
            }
            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%sc") == 0){
            char *value = va_arg(argptr,char*);
            stack->text(stack,value);
            free(value);
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%s") == 0){
            const char *value = va_arg(argptr,const char*);
            stack->text(stack,value);
            i+=1;
            continue;
        }
        else if(strcmp(double_test,"%tc") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            char *result = new_stack->self_transform_in_string_and_self_clear(new_stack);
            stack->text(stack,result);
            free(result);
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%t") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            stack->text(stack,new_stack->rendered_text);
            i+=1;
            continue;
        }

        char element[2] = {format[i],'\0'};
        stack->text(stack,element);

        }



    if(text_size > 0 && text_size> i){
        char element[2] = {format[text_size-1],'\0'};
        stack->text(stack,element);
    }




    va_end(argptr);
}
#endif // CTEXTENGINE_H