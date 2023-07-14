//
// Created by jurandi on 04-07-2023.
//
CTextArrayModule newCTextArrayModule(){
    CTextArrayModule self = {0};
    self.append_raw = CTextArray_append_raw;
    self.append_by_copy = CTextArray_append_by_copy;
    self.append_by_reference = CTextArray_append_by_reference;
    self.append_by_ownership = CTextArray_append_assuming_ownership;
    self.append_string =CTextArray_append_string;

    self.get_by_copy =CTextArray_get_by_copy;
    self.get_by_reference = CTextArray_get_by_reference;
    self.get_by_ownership =CTextArray_get_by_ownership;
    self.join =CTextArray_join;
    self.represent = CTextArray_represent;
    self.free = CTextArray_free;
    return self;

}