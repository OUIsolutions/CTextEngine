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

<!--codeof:exemples/basic_template.c--->


## Controling Scopes
with the breakline and separator, you can control the size of scopes in te way you want
these is an exemple of full mimifyed text 

<!--codeof:exemples/scopes.c--->


## Dealing with Conditions 
<!--codeof:exemples/conditions.c--->

## dealing with Loops
<!--codeof:exemples/loops.c--->


## Creating an log Visualiation
<!--codeof:exemples/loog_system.c--->


## An Sql Insert 
<!-- codeof:exemples/insert_sql.c-->



# Functions Api

## text
The **text**, Method is responsable for append new text into the stack 
<!-- codeof:exemples/text.c-->


## segment_text
Same as text, but will break an new line 

<!-- codeof:exemples/segment_text.c-->


## format
format has the same function as text, but allow formatations 

<!-- codeof:exemples/format.c-->


## segment_format
same as format, but breaking an line 

<!-- codeof:exemples/segment_format.c-->


## open 
Opens an new scope , if tag is NULL it will not render the current tag 

<!-- codeof:exemples/open.c-->


## $open
open an new scope but allowing you to pass an formated tag props 

<!-- codeof:exemples/open_with_args.c-->

## only$open 
Only open an scope , its ideal for "meta" tags 
<!-- codeof:exemples/only_open_with_args.c.c-->

## auto$close 
Implement an autoclose tag 

<!-- codeof:exemples/autoclose.c-->


## close 
Close the tag passed, if is null will only downcrease the ident 

<!-- codeof:exemples/close.c-->


## free
fre the alocated memory
<!-- codeof:exemples/free.c-->
