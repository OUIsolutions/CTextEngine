
#define CTEXT_BY_OWNERSHIP 1
#define CTEXT_BY_VALUE 2
#define CTEXT_BY_REFERENCE 3

typedef struct CTextArray{

    CTextStack **stacks;
    long stacks_sizes;
    bool *owerships;


}CTextArray;

CTextArray * newCTextArray();

CTextArray * CTextArray_append(CTextStack *stack,int mode);

CTextArray * CTextArray_append_string(char *element);

