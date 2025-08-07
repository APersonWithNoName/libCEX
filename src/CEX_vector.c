#include "libCEX/CEX_vector.h"
#include <stdlib.h>
#include <string.h>

CEX_vector* __CEX_vector_init(size_t _init_size, size_t _type_size)
{
    CEX_vector *__vec;

    __vec = malloc(sizeof(CEX_vector));
    if (!__vec) {
        return NULL;
    }

    __vec->_type_size = _type_size;
    __vec->_capacity = _init_size;
    __vec->_len = 0;
    __vec->_data = malloc(_init_size * sizeof(CEX_vector_item));
    if (!__vec->_data) {
        return NULL;
    }

    return __vec;
}


int CEX_vector_resize(CEX_vector *_vec, size_t _new_size)
{
    if (!_vec)
        return -1;

    CEX_vector_item *__new_data = realloc(_vec->_data, _new_size * sizeof(CEX_vector_item));
    if (!__new_data) {
        free(__new_data);
        return -1;
    }

    _vec->_data = __new_data;
    _vec->_capacity = _new_size;

    return 0;
}


int CEX_vector_push_back(CEX_vector *_vec, void *_data)
{
    CEX_vector_item *__item = &_vec->_data[_vec->_len];
    __item = malloc(_vec->_type_size);
    if (!__item) {
        return -1;
    }

    if (CEX_vector_push_back_item(_vec, __item) < 0) {
        free(__item);
        return -1;
    }

    memcpy(_vec->_data[_vec->_len]._data, _data, _vec->_type_size);
    _vec->_len++;

    free(__item);

    return 0;
}


int CEX_vector_push_back_item(CEX_vector *_vec, CEX_vector_item *_data)
{
    if (!_vec || sizeof(*_data) != _vec->_type_size)
        return -1;

    if (_vec->_capacity <= _vec->_len) {
        int __result = CEX_vector_resize(_vec, 2 * _vec->_capacity);
        if (__result != 0) {
            return -1;
        }
    }

    memcpy(_vec->_data[_vec->_len]._data, _data->_data, _vec->_type_size);
    _vec->_len++;

    return 0;
}


CEX_vector_item* CEX_vector_at(CEX_vector *_vec, size_t _index)
{
    if (_index >= _vec->_len) {
        return NULL;
    }

    return &_vec->_data[_index];
}


CEX_vector_item* CEX_vector_front(CEX_vector *_vec)
{
    if (_vec->_len == 0) {
        return NULL;
    }

    return CEX_vector_at(_vec, 0);
}


CEX_vector_item* CEX_vector_back(CEX_vector *_vec)
{
    if(_vec->_len == 0) {
        return NULL;
    }

    return CEX_vector_at(_vec, _vec->_len - 1);
}


int CEX_vector_erase(CEX_vector *_vec, size_t _pos)
{
    if (_pos >= _vec->_len) {
        return -1;
    }

    for (size_t i = _pos; i < _vec->_len; i++) {
        _vec->_data[i] = _vec->_data[i + 1];
    }
    _vec->_len--;

    return 0;
}


int CEX_vector_swap(CEX_vector *_vec, size_t _pos_a, size_t _pos_b)
{
    void *__tmp = malloc(_vec->_type_size);
    if (!__tmp) {
        return -1;
    }

    __tmp = _vec->_data[_pos_a]._data;
    _vec->_data[_pos_a]._data = _vec->_data[_pos_b]._data;
    _vec->_data[_pos_b]._data = __tmp;

    free(__tmp);

    return 0;
}


void CEX_vector_clear(CEX_vector *_vec)
{
    for (size_t i = 0; i < _vec->_len; i++) {
        memset(_vec->_data[i]._data, '\0', _vec->_type_size);
    }
}


int CEX_vector_empty(CEX_vector *_vec)
{
    if (_vec->_len == 0) {
        return 1;
    }
    return 0;
}


size_t CEX_vector_size(CEX_vector *_vec)
{
    return _vec->_len;
}



size_t CEX_vector_capacity(CEX_vector *_vec)
{
    return _vec->_capacity;
}


int CEX_vector_pop_back(CEX_vector *_vec)
{
    return CEX_vector_erase(_vec, _vec->_len - 1);
}


int CEX_vector_append(CEX_vector *_vec, CEX_vector *_data)
{
    if (!_vec || !_data) {
        return -1;
    }

    int __status;
    for (size_t i = 0; i < _data->_len; i++) {
        __status = CEX_vector_push_back(_vec, _data->_data[i]._data);
        if (__status < 0) {
            return -1;
        }
    }

    return 0;
}


void CEX_vector_free(CEX_vector *_vec)
{
    for (size_t i = 0; i < _vec->_len; i++) {
        free(_vec->_data[i]._data);
    }
    free(_vec->_data);
    free(_vec);
}
