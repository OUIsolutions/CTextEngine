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

~~~c


#include "CTextEngine.h"



int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);


    s->$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
        s->open(s,CTEXT_HEAD);
     
        s->close(s,CTEXT_HEAD);
        s->open(s,CTEXT_BODY);
            s->open(s,CTEXT_H1);
                s->segment_text(s,"This is a text");
            s->close(s,CTEXT_H1);
            s->open(s,CTEXT_P);
                s->segment_format(s,"This is a formated  text  %s",text);
            s->close(s,CTEXT_P);

        s->close(s,CTEXT_BODY);
    s->close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level = s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
   s->free(s);

}
~~~

## Controling Scopes
with the breakline and separator, you can control the size of scopes in te way you want
these is an exemple of full mimifyed text 
~~~c

#include "CTextEngine.h"



int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    const char *breakline = "";
    const char *separator = "";
    struct CTextStack *s = newCTextStack(breakline, separator);

    s->$open(s,CTEXT_HTML,"lang=\"%s\"",lang);
        s->open(s,CTEXT_HEAD);
     
        s->close(s,CTEXT_HEAD);
        s->open(s,CTEXT_BODY);
            s->open(s,CTEXT_H1);
                s->segment_text(s,"This is a text");
            s->close(s,CTEXT_H1);
            s->open(s,CTEXT_P);
                s->segment_format(s,"This is a formated  text  %s",text);
            s->close(s,CTEXT_P);

        s->close(s,CTEXT_BODY);
    s->close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level = s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
   s->free(s);

}

~~~

## Dealing with Conditions 

~~~c

#include "CTextEngine.h"



int main(){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    int age = 15;

    s->open(s,CTEXT_HTML);
        s->open(s,CTEXT_HEAD);
     
        s->close(s,CTEXT_HEAD);
        s->open(s,CTEXT_BODY);
            s->open(s,CTEXT_H1);
            if(age > 18)
                s->segment_text(s,"You are an adout");
            else if (age > 12)
                s->segment_text(s,"You are a child");
            else 
                s->segment_text(s,"You are a baby");
            s->close(s,CTEXT_H1);
        s->close(s,CTEXT_BODY);
    s->close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level = s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
   s->free(s);

}
~~~
## dealing with Loops

~~~c

#include "CTextEngine.h"



int main(){

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    const char *names[] = {"name1","name2","name3","name4","name 5"};


    s->open(s,CTEXT_HTML);
        s->open(s,CTEXT_HEAD);
     
        s->close(s,CTEXT_HEAD);
        s->open(s,CTEXT_BODY);
            for(int i = 0; i < sizeof(names)/ sizeof(char *) ; i++){
                s->open(s,CTEXT_H1);
                    s->segment_text(s,names[i]);
                s->close(s,CTEXT_H1);
            }

        s->close(s,CTEXT_BODY);
    s->close(s,CTEXT_HTML);

   printf("%s\n",s->rendered_text);
   int ident_level = s->ident_level;
   if(ident_level == 0){
        printf("all identation is ok\n");
    }else{
        printf("identation error\n");
        printf("unclosed tags: %d\n",ident_level);
    }
   s->free(s);

}
~~~

## Creating an log Visualiation

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

    struct Person john;
    john.name = "John";
    john.age = 20;
    john.car.name = "Ferrari";
    john.car.year = 2020;

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->format(s,"Name: %s",john.name);
    s->segment_format(s,"Age: %d",john.age);
    s->segment_text(s,"Car: ");
    s->open(s,NULL);
        s->segment_format(s,"Name: %s",john.car.name);
        s->segment_format(s,"Year: %d",john.car.year);
    s->close(s,NULL);
  
    printf("%s\n",s->rendered_text);
    int ident_level = s->ident_level;
    if(ident_level == 0){
            printf("all identation is ok\n");
        }else{
            printf("identation error\n");
            printf("unclosed tags: %d\n",ident_level);
        }
    s->free(s);
        
}
~~~

## An Sql Insert 


~~~c

#include "CTextEngine.h"


int main(){
    const char *table = "users";
    const char *columns[] = {"name","email","passord"};
    const char *values[] = {"John","john@email.com","1234"};

    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->format(s,"INSERT INTO '%s' (",table);
    s->open(s,NULL);
        s->segment_format(s,"'%s'",columns[0]);
        for(int i = 1; i < sizeof(columns)/ sizeof(char *) ; i++){
            s->format(s,",'%s'",columns[i]);
        }
    s->segment_text(s,")");
    s->close(s,NULL);

    s->segment_text(s,"VALUES (");
    s->open(s,NULL);    
        s->segment_format(s,"'%s'",values[0]);
        for(int i = 1; i < sizeof(values)/ sizeof(char *) ; i++){
            s->format(s,",'%s'",values[i]);
        }
    s->segment_text(s,")");
    s->close(s,NULL);
    
    
    printf("%s\n",s->rendered_text);
    int ident_level = s->ident_level;
    if(ident_level == 0){
            printf("all identation is ok\n");
        }else{
            printf("identation error\n");
            printf("unclosed tags: %d\n",ident_level);
        }
    s->free(s);
        

}
~~~

# Functions Api

## text
The **text**, Method is responsable for append new text into the stack 

~~~c

#include "CTextEngine.h"

int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->text(s,"test element");
   printf("%s\n",s->rendered_text);
   s->free(s);

}
~~~

## segment_text
Same as text, but will break an new line 

~~~c

#include "CTextEngine.h"
int main(){
   struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   s->segment_text(s,"test element");
   printf("%s\n",s->rendered_text);
   s->free(s);

}
~~~
## format
format has the same function as text, but allow formatations 

~~~c
#include "CTextEngine.h"

int main(){
    
   struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
   int age = 20;
   const char *name = "John";
   s->format(s,"Hes name is %s, he is %i years old ",name,age);
   printf("%s\n",s->rendered_text);
   s->free(s);

}
~~~
## segment_format
same as format, but breaking an line 
~~~c

#include "CTextEngine.h"

int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    int age = 20;
    const char *name = "John";
    s->segment_format(s,"Hes name is %s, he is %i years old ",name,age);
    printf("%s\n",s->rendered_text);
    s->free(s);
}
~~~
## open 
Opens an new scope , if tag is NULL it will not render the current tag 

~~~c

#include "CTextEngine.h"
int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->open(s,CTEXT_HTML);
    s->close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
    s->free(s);

}
~~~

## $open
open an new scope but allowing you to pass an formated tag props 
~~~c

#include "CTextEngine.h"

int main(){   
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *lang = "en";
    s->$open(s,CTEXT_HTML, "lang=\"%s\"",lang);
    s->close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
    s->free(s);
}
~~~

## only$open 
Only open an scope , its ideal for "meta" tags 

~~~c

#include "CTextEngine.h"

int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *name = "viewport";
    s->only$open(
        s,
        CTEXT_META, 
        "name=\"%s\" content=\"width=device-width, initial-scale=1.0",
        name
    );
    printf("%s\n",s->rendered_text);
    s->free(s);

}
~~~
## auto$close 
Implement an autoclose tag 
~~~c

#include "CTextEngine.h"

int main(){   
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    const char *src = "img.com";
    s->auto$close(s,CTEXT_IMG,"src=\"%s\"",src);
    printf("%s\n",s->rendered_text);
    s->free(s);

}
~~~
## close 
Close the tag passed, if is null will only downcrease the ident 
~~~c
#include "CTextEngine.h"

int main(){
    
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->open(s,CTEXT_HTML);
    s->close(s,CTEXT_HTML);
    printf("%s\n",s->rendered_text);
    s->free(s);
}

~~~

## free
fre the alocated memory
~~~c
#include "CTextEngine.h"
int main(){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->free(s);

}
~~~