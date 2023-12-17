#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct LISTY_node* LISTY_node_h;
typedef struct LISTY_node const* LISTY_const_node_h;
typedef struct LISTY_list* LISTY_list_h;
typedef struct LISTY_list const* LISTY_const_list_h;

typedef enum
{
    LISTY_ORDER_ASCENDING = -1,
    LISTY_ORDER_DESCENDING = 1
} LISTY_order_t;

typedef enum
{
    LISTY_FROM_HEAD,
    LISTY_FROM_TAIL,
} LISTY_iter_t;

typedef struct LISTY_find_ret
{
    LISTY_node_h target;
    LISTY_node_h prev;
} LISTY_find_ret_t;

/*
    Dynamically allocates memory for a new list data type.

    It accepts 4 functions pointers:
    - a copy function, which copies the data to a new list node
    - a delete function, which deletes the data from an existing list node
    - a compare function, which compares the data between two list nodes
      - returns -1 if lhs < rhs
      - returns 0 if lhs == rhs
      - returns 1 if lhs > rhs
    - a get_key function, which is used to find and sort data
    
    It returns a pointer to the newly-created list or NULL, if there's an error. 
*/
LISTY_list_h LISTY_new_list(void* (*)(void const*), void (*)(void*), 
    int (*)(void const*, void const*), void const* (*)(void const*),
    LISTY_order_t);

LISTY_find_ret_t LISTY_find(LISTY_list_h, void const*);

LISTY_node_h LISTY_insert(LISTY_list_h, void const*);

LISTY_node_h LISTY_emplace(LISTY_list_h, void**);

void* LISTY_remove(LISTY_list_h, LISTY_node_h);

void LISTY_traverse(LISTY_list_h, bool (*)(void*, void**), void**, 
    LISTY_iter_t);

void* LISTY_get_data(LISTY_node_h);

LISTY_node_h LISTY_get_head(LISTY_list_h);

LISTY_node_h LISTY_get_tail(LISTY_list_h);

LISTY_node_h LISTY_get_next(LISTY_node_h);

LISTY_node_h LISTY_get_prev(LISTY_node_h);

size_t LISTY_get_size(LISTY_const_list_h);

bool LISTY_is_empty(LISTY_const_list_h);

void LISTY_clear(LISTY_list_h);

void LISTY_delete_list(LISTY_list_h);
