#ifndef __CEX_STRING_H__
#define __CEX_STRING_H__

#include <string.h>

#include "libCEX/CEX_vector.h"

typedef CEX_vector_item CEX_string_char;
typedef CEX_vector CEX_string;

CEX_string* CEX_string_init();

int CEX_string_assign(CEX_string *_str, char *_c_str);

size_t CEX_string_size(CEX_string *_str);

size_t CEX_string_capacity(CEX_string *_str);

int CEX_string_resize(CEX_string *_str, size_t _new_size);

void CEX_string_clear(CEX_string *_str);

int CEX_string_empty(CEX_string *_str);

int CEX_string_push_back(CEX_string *_str, char *_data);

int CEX_string_push_back_char(CEX_string *_str, CEX_string_char *_data);

int CEX_string_swap(CEX_string *_a, CEX_string *_b);

int CEX_string_earse(CEX_string *_str, size_t _pos);

int CEX_string_append(CEX_string *_str, CEX_string *_data);

CEX_string_char* CEX_string_at(CEX_string *_str, size_t _pos);

CEX_string_char* CEX_string_back(CEX_string *_str);

CEX_string_char* CEX_string_front(CEX_string *_str);

// 在使用后调用 free 函数
CEX_string* CEX_string_insert(CEX_string *_str, size_t _pos, CEX_string *_src);

// 在使用后调用 free 函数
CEX_string* CEX_string_substr(CEX_string *_str, size_t _pos, size_t _len);

// 在使用后调用 free 函数
char* CEX_string_c_str(CEX_string *_str);

void CEX_string_free(CEX_string* _str);

#endif /* __CEX_STRING_H__ */