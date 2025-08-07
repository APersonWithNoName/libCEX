#include "libCEX/CEX_string.h"
#include "libCEX/CEX_vector.h"
#include <string.h>

CEX_string* CEX_string_init()
{
    CEX_string* __str;
    __str = __CEX_vector_init(2, sizeof(char));
    return __str;
}


int CEX_string_assign(CEX_string *_str, char *_c_str)
{
    CEX_string_clear(_str);
    size_t __c_str_len = strlen(_c_str);

    if (_str->_capacity < __c_str_len) {
        if (CEX_string_resize(_str, __c_str_len) < 0) {
            return -1;
        }
    }

    for (size_t i = 0; i < __c_str_len; i++) {
        if (CEX_string_push_back(_str, &_c_str[i]) < 0) {
            return -1;
        }
    }

    return 0;
}


size_t CEX_string_size(CEX_string *_str)
{
    return CEX_vector_size(_str);
}


size_t CEX_string_capacity(CEX_string *_str)
{
    return CEX_vector_size(_str);
}


int CEX_string_resize(CEX_string *_str, size_t _new_size)
{
    return CEX_vector_resize(_str, _new_size);
}


void CEX_string_clear(CEX_string *_str)
{
    CEX_vector_clear(_str);
}


int CEX_string_empty(CEX_string *_str)
{
    return CEX_string_empty(_str);
}


int CEX_string_push_back(CEX_string *_str, char *_data)
{
    return CEX_vector_push_back(_str, (void*)_data);
}


int CEX_string_push_back_char(CEX_string *_str, CEX_string_char *_data)
{
    return CEX_vector_push_back_item(_str, _data);
}


int CEX_string_swap(CEX_string *_a, CEX_string *_b)
{
    CEX_string *__tmp = malloc(sizeof(char));
    if (!__tmp) {
        return -1;
    }

    __tmp = _a;
    _a = _b;
    _b = __tmp;

    free(__tmp);

    return 0;
}


int CEX_string_earse(CEX_string *_str, size_t _pos)
{
    return CEX_vector_erase(_str, _pos);
}


int CEX_string_append(CEX_string *_str, CEX_string *_data)
{
    return CEX_vector_append(_str, _data);
}


char* CEX_string_c_str(CEX_string *_str)
{
    char *__ret = malloc(_str->_len + 1);
    if (!__ret) {
        return NULL;
    }

    for (size_t i = 0; i < _str->_len; i++) {
        strcpy(__ret, _str->_data[i]._data);
    }
    __ret[_str->_len] = '\0';

    return __ret;
}


CEX_string* CEX_string_substr(CEX_string *_str, size_t _pos, size_t _len)
{
    CEX_string *__substr = CEX_string_init();
    if (!__substr) {
        return NULL;
    }

    for (size_t i = 0; i < _len; i++) {
        if (CEX_vector_push_back_item(__substr, CEX_vector_at(_str, _pos + i)) < 0) {
            return __substr;
        }
    }

    return __substr;
}


CEX_string_char* CEX_string_at(CEX_string *_str, size_t _pos)
{
    return (CEX_string_char*)CEX_vector_at(_str, _pos);
}


CEX_string_char* CEX_string_back(CEX_string *_str)
{
    return (CEX_string_char*)CEX_vector_back(_str);
}


CEX_string_char* CEX_string_front(CEX_string *_str)
{
    return (CEX_string_char*)CEX_vector_front(_str);
}


CEX_string* CEX_string_insert(CEX_string *_str, size_t _pos, CEX_string *_src)
{
    if (!_str || !_src) {
        return NULL;
    }

    CEX_string *__ret = CEX_string_init();
    CEX_string *__before = CEX_string_init();
    CEX_string *__after = CEX_string_init();
    if (!__before || !__after || !__ret) {
        return NULL;
    }

    for (size_t i = 0; i < _pos; i++) {
        CEX_string_push_back_char(__before, CEX_string_at(_str, i));
    }
    for (size_t i = _pos; i < _str->_len; i++) {
        CEX_string_push_back_char(__after, CEX_string_at(_str, i));
    }

    CEX_string_append(__ret, __before);
    CEX_string_append(__ret, _src);
    CEX_string_append(__ret, __after);

    return __ret;
}





void CEX_string_free(CEX_string* _str)
{
    CEX_vector_free(_str);
}