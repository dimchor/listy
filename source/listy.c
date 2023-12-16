#include "../include/listy.h"

typedef struct LISTY_node
{
    struct node* _next;
    struct node* _prev;

    void* _data;
} LISTY_node_t;

typedef struct LISTY_list
{
    LISTY_node_h _head;
    LISTY_node_h _tail;

    uint64_t _size;

    void* (*_copy)(void const*);
    void* (*_del)(void*);
    int (*_cmp)(void const*, void const*);
    void const* (*_get_key)(void const*);
} LISTY_list_t;

LISTY_list_h LISTY_new_list(void* (*copy)(void const*), void* (*del)(void*), 
    int (*cmp)(void const*, void const*), void const* (*get_key)(void const*))
{
    LISTY_list_h list = malloc(sizeof(LISTY_list_t));
    if (!list)
    {
        return NULL;
    }

    list->_head = NULL;
    list->_tail = NULL;
    list->_size = 0;

    list->_copy = copy;
    list->_del = del;
    list->_cmp = cmp;
    list->_get_key = get_key;
    
    return list;
}

void LISTY_delete_list(LISTY_list_h list_handle)
{
    /*
        Incomplete!
    */
    free(list_handle);
}
