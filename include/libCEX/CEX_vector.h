#ifndef __CEX_VECTOR_H__
#define __CEX_VECTOR_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    void *_data;
} CEX_vector_item;

typedef struct {
    size_t _len;
    size_t _capacity;
    size_t _type_size;
    CEX_vector_item *_data;
} CEX_vector;

#define CEX_vector_init(obj, type) \
    obj = __CEX_vector_init(2, sizeof(type));


CEX_vector* __CEX_vector_init(size_t _init_size, size_t _type_size);

int CEX_vector_push_back(CEX_vector *_vec, void *_data);

int CEX_vector_push_back_item(CEX_vector *_vec, CEX_vector_item *_data);

int CEX_vector_resize(CEX_vector *_vec, size_t _new_size);

CEX_vector_item* CEX_vector_at(CEX_vector *_vec, size_t _index);

CEX_vector_item* CEX_vector_front(CEX_vector *_vec);

CEX_vector_item* CEX_vector_back(CEX_vector *_vec);

int CEX_vector_erase(CEX_vector *_vec, size_t _pos);

int CEX_vector_swap(CEX_vector *_vec, size_t _pos_a, size_t _pos_b);

int CEX_vector_empty(CEX_vector *_vec);

void CEX_vector_clear(CEX_vector *_vec);

size_t CEX_vector_size(CEX_vector *_vec);

size_t CEX_vector_capacity(CEX_vector *_vec);

int CEX_vector_pop_back(CEX_vector *_vec);

int CEX_vector_append(CEX_vector *_vec, CEX_vector *_data);

void CEX_vector_free(CEX_vector *_vec);

#endif /* __CEX_VECTOR_H__ */
