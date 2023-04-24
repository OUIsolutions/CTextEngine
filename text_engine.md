

[link to library](https://github.com/OUIsolutions/CTextEngine)

CTextEngine is a single Header text rendering engine, focused (but not limited) to html/xml documents. It is Completely Open Source and  distributed under MIT license.


## Functionalities:
   - tag control
   - Text Formatting
   - Scope control (useful for documents sensitive to blank lines (yaml, python))

## Disclaimers
Although it is possible to generate any document with the lib, (yaml,json,cfg,html) , this is not a parser, which means that it is not possible to read and interpret documents, it only generates them

## Generating an HTML 

~~~c

#include "CTextEngine.h"



int main(){
    const char *lang = "en";
    const char *text = "text exemple";
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);

    s->$open(s,HTML,"lang=\"%s\"",lang);
        s->open(s,HEAD);
        
        s->close(s,HEAD);
        s->open(s,BODY);
            s->open(s,H1);
                s->segment_text(s,"This is a text");
            s->close(s,H1);
            s->open(s,P);
                s->segment_format(s,"This is a formated  text  %s",text);
            s->close(s,P);

        s->close(s,BODY);
    s->close(s,HTML);

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

## Generating An Log 

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

## Generating an SQL Insertion 

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