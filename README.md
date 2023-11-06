# CTextEngine

CTextEngine its an full scope_already_opended source single header C/C++ text engine for general propose focused  on html/xml documents, with CTextEngine you can generate 
various kinds of documents with easy steps


# Instalation
## Single File
As Others OUI Products, these lib is made to bee dumb as possible,so for instalation
you can just copy the **CTextEngine.h** file  to your project and start using

if these runs, it means it working
~~~c
#include "CTextEngine.h"

int main(){

}
~~~


## Full Folder
You also can run by full folder , just copy the entire folder i **CTextEngine** in your project 
than run with:
~~~c
#include "CTextEngine/CTextEngineMain.h"


int main(){

}
~~~

# Usage 

## Rendering an basic Template 

<!--codeof:exemples/scopes/basic_template.c-->
~~~c

#include "CTextEngine.h"



int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
  
   stack.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
       stack.open(s,CTEXT_HEAD);
        
       stack.close(s,CTEXT_HEAD);
       stack.open(s,CTEXT_BODY);
           stack.open(s,CTEXT_H1);
               stack.segment_text(s,"This is a text");
           stack.close(s,CTEXT_H1);
           stack.open(s,CTEXT_P);
               stack.segment_format(s,"This is a formated  text  %s",text);
           stack.close(s,CTEXT_P);

       stack.close(s,CTEXT_BODY);
   stack.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
       ctext.stack.free(s);
        return 1;
    }

  stack.free(s);

}
~~~

## Rendering an basic Template with scope mode

<!--codeof:exemples/macros/scope_macro.c-->
~~~c
#include "CTextEngine.h"

int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *lang = "en";
    const char *text = "text exemple";
    CText$Scope(s, CTEXT_HTML,"lang=\"%s\"",lang){
        CTextScope(s,CTEXT_HEAD){}
        CTextScope(s,CTEXT_BODY){
            CTextScope(s,CTEXT_H1){
                stack.segment_text(s,"This is a text");
            }
            CTextScope(s,CTEXT_P){
                stack.segment_format(s,"This is a formated  text  %s",text);

            }
        }
    }

    printf("%s\n",s->rendered_text);

    stack.free(s);
}
~~~

with the breakline and separator, you can control the size of scopes in te way you want
these is an exemple of full mimifyed text 

<!--codeof:exemples/scopes/scopes.c-->
~~~c
#include "CTextEngine.h"

int main(){


    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    const char *lang = "en";
    const char *text = "text exemple";
    const char *breakline = "";
    const char *separator = "";
    CTextStack *s = stack.newStack(breakline, separator);

  stack.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
      stack.open(s,CTEXT_HEAD);
     
      stack.close(s,CTEXT_HEAD);
      stack.open(s,CTEXT_BODY);
          stack.open(s,CTEXT_H1);
              stack.segment_text(s,"This is a text");
          stack.close(s,CTEXT_H1);
          stack.open(s,CTEXT_P);
              stack.segment_format(s,"This is a formated  text  %s",text);
          stack.close(s,CTEXT_P);

      stack.close(s,CTEXT_BODY);
  stack.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
 stack.free(s);

}
~~~
<!--codeof:exemples/scopes/conditions.c-->
~~~c

#include "CTextEngine.h"



int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int age = 15;

   stack.open(s,CTEXT_HTML);
       stack.open(s,CTEXT_HEAD);
     
       stack.close(s,CTEXT_HEAD);
       stack.open(s,CTEXT_BODY);
           stack.open(s,CTEXT_H1);
            if(age > 18)
               stack.segment_text(s,"You are an adout");
            else if (age > 12)
               stack.segment_text(s,"You are a child");
            else 
               stack.segment_text(s,"You are a baby");
           stack.close(s,CTEXT_H1);
       stack.close(s,CTEXT_BODY);
   stack.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
  stack.free(s);

}
~~~
<!--codeof:exemples/scopes/loops.c-->
~~~c

#include "CTextEngine.h"



int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *names[] = {"name1","name2","name3","name4","name 5"};

  stack.open(s,CTEXT_HTML);
      stack.open(s,CTEXT_HEAD);
     
      stack.close(s,CTEXT_HEAD);
      stack.open(s,CTEXT_BODY);
            for(int i = 0; i < sizeof(names)/ sizeof(char *) ; i++){
              stack.open(s,CTEXT_H1);
                  stack.segment_text(s,names[i]);
              stack.close(s,CTEXT_H1);
            }

      stack.close(s,CTEXT_BODY);
  stack.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
 stack.free(s);

}
~~~
<!--codeof:exemples/scopes/log_system.c-->
~~~c

#include "CTextEngine.h"


struct Car {
    const char *name;
    int year;
};

struct Person {
    const char *name;
    int age;
    struct Car car;

};


int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct Person john;
    john.name = "John";
    john.age = 20;
    john.car.name = "Ferrari";
    john.car.year = 2020;

    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

  stack.format(s,"Name: %s",john.name);
  stack.segment_format(s,"Age: %d",john.age);
  stack.segment_text(s,"Car: ");
  stack.open(s,NULL);
      stack.segment_format(s,"Name: %s",john.car.name);
      stack.segment_format(s,"Year: %d",john.car.year);
  stack.close(s,NULL);
  
    printf("%s\n",s->rendered_text);

  stack.free(s);
        

}
~~~
<!--codeof:exemples/scopes/insert_sql.c-->
~~~c

#include "CTextEngine.h"




int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    const char *table = "users";
    const char *columns[] = {"name","email","passord"};
    const char *values[] = {"John","john@email.com","1234"};

    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   stack.format(s,"INSERT INTO '%s' (",table);
   stack.open(s,NULL);
       stack.segment_format(s,"'%s'",columns[0]);
        for(int i = 1; i < sizeof(columns)/ sizeof(char *) ; i++){
           stack.format(s,",'%s'",columns[i]);
        }
   stack.segment_text(s,")");
   stack.close(s,NULL);

   stack.segment_text(s,"VALUES (");
   stack.open(s,NULL);    
       stack.segment_format(s,"'%s'",values[0]);
        for(int i = 1; i < sizeof(values)/ sizeof(char *) ; i++){
           stack.format(s,",'%s'",values[i]);
        }
   stack.segment_text(s,")");
   stack.close(s,NULL);
    

    printf("%s\n",s->rendered_text);

   stack.free(s);
        

}
~~~

## text
The **text**, Method is responsable for append new text into the stack 
<!--codeof:exemples/stack_manipulation/text.c-->
~~~c

#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    
    struct CTextStack *s = stack.newStack_string_empty();

  stack.text(s,"test element");
   printf("%s\n",s->rendered_text);
 stack.free(s);

}
~~~
Same as text, but will break an new line 

<!--codeof:exemples/stack_manipulation/segment_text.c-->
~~~c
#include "CTextEngine.h"
int main(){
    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
 stack.segment_text(s,"test element");
   printf("%s\n",s->rendered_text);
 stack.free(s);

}
~~~
format has the same function as text, but allow formatations 

<!--codeof:exemples/stack_manipulation/format.c-->
~~~c

#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack_string_empty();
    int age = 20;
    const char *name = "John";
   stack.format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
   stack.free(s);

}
~~~
same as format, but breaking an line 

<!--codeof:exemples/stack_manipulation/segment_format.c-->
~~~c

#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    int age = 20;
    const char *name = "John";
  stack.segment_format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
  stack.free(s);
}
~~~
Opens an new scope , if tag is NULL it will not render the current tag 

<!--codeof:exemples/scopes/open.c-->
~~~c
#include "CTextEngine.h"
int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;
    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
  stack.open(s,CTEXT_HTML);
  stack.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
  stack.free(s);

}
~~~
scope_already_opended an new scope but allowing you to pass an formated tag props 

<!--codeof:exemples/scopes/open_with_args.c-->
~~~c
#include "CTextEngine.h"

int main(){


    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *lang = "en";
  stack.$open(s,CTEXT_HTML, "lang=\"%s\"",lang);
  stack.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
  stack.free(s);
}
~~~
Only scope_already_opended an scope , its ideal for "meta" tags 
<!--codeof:exemples/scopes/only_open_with_args.c-->
~~~c


#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *name = "viewport";
  stack.only$open(
        s,
        CTEXT_META, 
        "name=\"%s\" content=\"width=device-width, initial-scale=1.0",
        name
    );
    printf("%s\n",s->rendered_text);
  stack.free(s);

}
~~~
Implement an autoclose tag 

<!--codeof:exemples/scopes/autoclose.c-->
~~~c


#include "CTextEngine.h"

int main(){

    CTextNamespace ctext = newCTextNamespace();
    CTextStackModule stack = ctext.stack;

    struct CTextStack *s = stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *src = "img.com";
    stack.auto$close(s,CTEXT_IMG,"src=\"%s\"",src);
    printf("%s\n",s->rendered_text);
    stack.free(s);
   
    
}
~~~
Close the tag passed, if is null will only downcrease the ident 

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.scope_already_opended(s,CTEXT_HTML);
   m.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   m.free(s);
}
~~~
free the alocated memory
<!--codeof:exemples/basic/free.c-->
~~~c
#include "CTextEngine.h"
int main(){
    CTextNamespace ctext = newCTextNamespace();

    struct CTextStack *s = ctext.stack.newStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    ctext.stack.free(s);

}
~~~