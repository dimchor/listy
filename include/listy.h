#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct LISTY_node* LISTY_node_h;
typedef struct LISTY_list* LISTY_list_h;

/*
    Dynamically allocates memory for a new list data type.

    It accepts 4 functions pointers:
        - a copy function, which copies the data to a new list node
        - a delete function, which deletes the data from an existing list node
        - a compare function, which compares the data between two list nodes
        - a get_key function, which is used to find and sort data
    
    It returns a pointer to the newly-created list or NULL, if there's an error. 
*/
LISTY_list_h LISTY_new_list(void* (*)(void const*), void* (*)(void*), 
    int (*)(void const*, void const*), void const* (*)(void const*));

void LISTY_delete_list(LISTY_list_h);