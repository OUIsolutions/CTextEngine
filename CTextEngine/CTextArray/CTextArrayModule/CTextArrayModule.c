

CTextArrayModule newCTextArrayModule(){
    CTextArrayModule module = {0};
    module.append = CTextArray_append;
    module.append_string = CTextArray_append_string;
    module.join = CTextArray_join;
    module.free = CTextArray_free;
    return module;
}
