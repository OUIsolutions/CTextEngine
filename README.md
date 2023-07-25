# CTextEngine

CTextEngine its an full open source single header C/C++ text engine for general propose focused  on html/xml documents, with CTextEngine you can generate 
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
    CTextStackModule m = newCTextStackModule();

    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
  
   m.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
       m.open(s,CTEXT_HEAD);
        
       m.close(s,CTEXT_HEAD);
       m.open(s,CTEXT_BODY);
           m.open(s,CTEXT_H1);
               m.segment_text(s,"This is a text");
           m.close(s,CTEXT_H1);
           m.open(s,CTEXT_P);
               m.segment_format(s,"This is a formated  text  %s",text);
           m.close(s,CTEXT_P);

       m.close(s,CTEXT_BODY);
   m.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
       m.free(s);
        return 1;
    }

  m.free(s);

}
~~~
with the breakline and separator, you can control the size of scopes in te way you want
these is an exemple of full mimifyed text 

<!--codeof:exemples/scopes/scopes.c-->
~~~c
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    const char *lang = "en";
    const char *text = "text exemple";
    const char *breakline = "";
    const char *separator = "";
    CTextStack *s = newCTextStack(breakline, separator);

   m.$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
       m.open(s,CTEXT_HEAD);
     
       m.close(s,CTEXT_HEAD);
       m.open(s,CTEXT_BODY);
           m.open(s,CTEXT_H1);
               m.segment_text(s,"This is a text");
           m.close(s,CTEXT_H1);
           m.open(s,CTEXT_P);
               m.segment_format(s,"This is a formated  text  %s",text);
           m.close(s,CTEXT_P);

       m.close(s,CTEXT_BODY);
   m.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
  m.free(s);

}
~~~
<!--codeof:exemples/scopes/conditions.c-->
~~~c

#include "CTextEngine.h"



int main(){
    CTextStackModule m = newCTextStackModule();

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int age = 15;

   m.open(s,CTEXT_HTML);
       m.open(s,CTEXT_HEAD);
     
       m.close(s,CTEXT_HEAD);
       m.open(s,CTEXT_BODY);
           m.open(s,CTEXT_H1);
            if(age > 18)
               m.segment_text(s,"You are an adout");
            else if (age > 12)
               m.segment_text(s,"You are a child");
            else 
               m.segment_text(s,"You are a baby");
           m.close(s,CTEXT_H1);
       m.close(s,CTEXT_BODY);
   m.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
  m.free(s);

}
~~~
<!--codeof:exemples/scopes/loops.c-->
~~~c

#include "CTextEngine.h"



int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *names[] = {"name1","name2","name3","name4","name 5"};

   m.open(s,CTEXT_HTML);
       m.open(s,CTEXT_HEAD);
     
       m.close(s,CTEXT_HEAD);
       m.open(s,CTEXT_BODY);
            for(int i = 0; i < sizeof(names)/ sizeof(char *) ; i++){
               m.open(s,CTEXT_H1);
                   m.segment_text(s,names[i]);
               m.close(s,CTEXT_H1);
            }

       m.close(s,CTEXT_BODY);
   m.close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level =s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
  m.free(s);

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
    CTextStackModule m = newCTextStackModule();

    struct Person john;
    john.name = "John";
    john.age = 20;
    john.car.name = "Ferrari";
    john.car.year = 2020;

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

   m.format(s,"Name: %s",john.name);
   m.segment_format(s,"Age: %d",john.age);
   m.segment_text(s,"Car: ");
   m.open(s,NULL);
       m.segment_format(s,"Name: %s",john.car.name);
       m.segment_format(s,"Year: %d",john.car.year);
   m.close(s,NULL);
  
    printf("%s\n",s->rendered_text);

   m.free(s);
        

}
~~~
<!--codeof:exemples/scopes/insert_sql.c-->
~~~c

#include "CTextEngine.h"




int main(){
    CTextStackModule m = newCTextStackModule();

    const char *table = "users";
    const char *columns[] = {"name","email","passord"};
    const char *values[] = {"John","john@email.com","1234"};

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.format(s,"INSERT INTO '%s' (",table);
   m.open(s,NULL);
       m.segment_format(s,"'%s'",columns[0]);
        for(int i = 1; i < sizeof(columns)/ sizeof(char *) ; i++){
           m.format(s,",'%s'",columns[i]);
        }
   m.segment_text(s,")");
   m.close(s,NULL);

   m.segment_text(s,"VALUES (");
   m.open(s,NULL);    
       m.segment_format(s,"'%s'",values[0]);
        for(int i = 1; i < sizeof(values)/ sizeof(char *) ; i++){
           m.format(s,",'%s'",values[i]);
        }
   m.segment_text(s,")");
   m.close(s,NULL);
    

    printf("%s\n",s->rendered_text);

   m.free(s);
        

}
~~~

## text
The **text**, Method is responsable for append new text into the stack 
<!--codeof:exemples/stack_manipulation/text.c-->
~~~c

#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack_string_empty();

   m.text(s,"test element");
   printf("%s\n",s->rendered_text);
  m.free(s);

}
~~~
Same as text, but will break an new line 

<!--codeof:exemples/stack_manipulation/segment_text.c-->
~~~c
#include "CTextEngine.h"
int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
  m.segment_text(s,"test element");
   printf("%s\n",s->rendered_text);
  m.free(s);

}
~~~
format has the same function as text, but allow formatations 

<!--codeof:exemples/stack_manipulation/format/format.c-->
~~~c

#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack_string_empty();
    int age = 20;
    const char *name = "John";
    m.format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
    m.free(s);

}
~~~
same as format, but breaking an line 

<!--codeof:exemples/stack_manipulation/segment_format.c-->
~~~c

#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    int age = 20;
    const char *name = "John";
   m.segment_format(s,"Hes name is %s, he is %d years old ",name,age);
    printf("%s\n",s->rendered_text);
   m.free(s);
}
~~~
Opens an new scope , if tag is NULL it will not render the current tag 

<!--codeof:exemples/scopes/open/open.c-->
~~~c
#include "CTextEngine.h"
int main(){
    CTextStackModule m = newCTextStackModule();

    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.open(s,CTEXT_HTML);
   m.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   m.free(s);

}
~~~
open an new scope but allowing you to pass an formated tag props 

<!--codeof:exemples/scopes/open_with_args.c-->
~~~c
#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *lang = "en";
   m.$open(s,CTEXT_HTML, "lang=\"%s\"",lang);
   m.close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
   m.free(s);
}
~~~
Only open an scope , its ideal for "meta" tags 
<!--codeof:exemples/scopes/only_open_with_args.c-->
~~~c


#include "CTextEngine.h"

int main(){
    CTextStackModule m = newCTextStackModule();
    CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *name = "viewport";
   m.only$open(
        s,
        CTEXT_META, 
        "name=\"%s\" content=\"width=device-width, initial-scale=1.0",
        name
    );
    printf("%s\n",s->rendered_text);
   m.free(s);

}
~~~
Implement an autoclose tag 

<!--codeof:exemples/scopes/autoclose/autoclose.c-->
~~~c


#include "CTextEngine.h"

int main(){

    CTextStackModule m = newCTextStackModule();
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *src = "img.com";
    m.auto$close(s,CTEXT_IMG,"src=\"%s\"",src);
    printf("%s\n",s->rendered_text);
    m.free(s);
   
    
}
~~~
Close the tag passed, if is null will only downcrease the ident 

int main(){
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.open(s,CTEXT_HTML);
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
    CTextStackModule m = newCTextStackModule();

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   m.free(s);

}
~~~