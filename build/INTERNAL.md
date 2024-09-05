
# CTextEngine

CTextEngine its single file C/C++ text engine for general propose, focused  on html/xml
documents, with CTextEngine you can generate various kinds of documents with easy steps

# Instalation
## Single File
As Others OUI Products, these lib is made to bee dumb as possible,so for instalation
you can just copy the [CTextEngine.h](https://github.com/OUIsolutions/CTextEngine/releases/download/v2.002/CTextEngine.h) file  to your project and start using

if these runs, it means it working
~~~c
#include "CTextEngine.h"

int main(){

}
~~~


## Full Folder
You also can run by full folder , just copy the entire folder **src** in your project
than run with:
~~~c
#include "src/one.c"

int main(){

}
~~~

# Usage

## Rendering an basic Template

codeof:exemples/scopes/basic_template.c

## Rendering an basic Template with scope mode

codeof:exemples/macros/scope_macro.c


with the breakline and separator, you can control the size of scopes in te way you want
these is an exemple of full mimifyed text

codeof:exemples/scopes/scopes.c


codeof:exemples/scopes/conditions.c

codeof:exemples/scopes/loops.c


codeof:exemples/scopes/log_system.c

codeof:exemples/scopes/insert_sql.c

## text
The **text**, Method is responsable for append new text into the stack

codeof:exemples/stack_manipulation/text.c

Same as text, but will break an new line

codeof:exemples/stack_manipulation/segment_text.c

format has the same function as text, but allow formatations

codeof:exemples/stack_manipulation/format.c

same as format, but breaking an line

codeof:exemples/stack_manipulation/segment_format.c

Opens an new scope , if tag is NULL it will not render the current tag

codeof:exemples/scopes/open.c

scope_already_opended an new scope but allowing you to pass an formated tag props

codeof:exemples/scopes/open_with_args.c

Only scope_already_opended an scope , its ideal for "meta" tags
codeof:exemples/scopes/only_open_with_args.c

Implement an autoclose tag

codeof:exemples/scopes/autoclose.c


free the alocated memory
codeof:exemples/basic/free.c
