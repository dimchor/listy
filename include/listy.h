#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct LISTY_node* LISTY_node_h;
typedef struct LISTY_list* LISTY_list_h;

typedef enum LISTY_ordering
{
    LISTY_ORDERING_ASCENDING,
    LISTY_ORDERING_DESCENDING
} LISTY_ordering_t;

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
LISTY_list_h LISTY_new_list(void* (*)(void const*), void* (*)(void*), 
    int (*)(void const*, void const*), void const* (*)(void const*),
    LISTY_ordering_t);

void LISTY_delete_list(LISTY_list_h);