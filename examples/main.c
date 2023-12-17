#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "../include/listy.h"

typedef struct
{
    char full_name[64];
    uint8_t age;

} client_record_t;

typedef client_record_t* client_record_h;
typedef client_record_t const* client_const_record_h;

client_record_h new_client_record(char full_name[64], uint8_t age)
{
    client_record_h client_handle = malloc(sizeof(client_record_t));
    if (!client_handle)
    {
        return NULL;
    }

    strcpy(client_handle->full_name, full_name);
    client_handle->age = age;

    return client_handle;
}

client_record_h copy_client_record(client_const_record_h client_handle)
{
    return new_client_record(client_handle->full_name, client_handle->age);
}

int cmp_client_record(client_const_record_h lhs, client_const_record_h rhs)
{
    int ret = strcmp(lhs->full_name, rhs->full_name);
    return ret < 0 ? -1 : ret > 0 ? 1 : 0;
}

char const* get_key_client_record(client_const_record_h client_handle)
{
    return client_handle->full_name;
}

void print_client_record(client_record_h client_handle, void** other)
{
    printf("full name: %s, age: %u\n", client_handle->full_name, 
        +client_handle->age);
}

void delete_client_record(client_record_h client_handle)
{
    free(client_handle);
}

int main(void)
{
    puts("hello, world");

    
    LISTY_list_h list = LISTY_new_list(copy_client_record, 
        delete_client_record, cmp_client_record, get_key_client_record, 
        LISTY_ORDER_ASCENDING);

    client_record_h client = new_client_record("b", 20);
    LISTY_node_h b = LISTY_insert(list, client);
    delete_client_record(client);

    client = new_client_record("a", 10);
    LISTY_node_h a = LISTY_emplace(list, &client);
    // do not delete anything this time

    client = new_client_record("d", 40);
    LISTY_node_h d = LISTY_emplace(list, &client);

    client = new_client_record("c", 30);
    LISTY_node_h c = LISTY_emplace(list, &client);

    print_client_record(LISTY_get_data(LISTY_get_head(list)), NULL);
    print_client_record(LISTY_get_data(LISTY_get_tail(list)), NULL);
    print_client_record(LISTY_get_data(LISTY_get_prev(b)), NULL);
    print_client_record(LISTY_get_data(LISTY_get_next(b)), NULL);
    printf("%d, %s\n", LISTY_get_size(list), (LISTY_is_empty(list) 
                                                  ? "true" 
                                                  : "false"));


    delete_client_record(LISTY_remove(list, c));
    LISTY_traverse(list, print_client_record, NULL, LISTY_FROM_TAIL);

    delete_client_record(LISTY_remove(list, d));
    LISTY_traverse(list, print_client_record, NULL, LISTY_FROM_TAIL);

    delete_client_record(LISTY_remove(list, a));
    LISTY_traverse(list, print_client_record, NULL, LISTY_FROM_TAIL);

    delete_client_record(LISTY_remove(list, b));
    LISTY_traverse(list, print_client_record, NULL, LISTY_FROM_TAIL);

    printf("%d, %s\n", LISTY_get_size(list), (LISTY_is_empty(list) 
                                                  ? "true" 
                                                  : "false"));

    LISTY_delete_list(list);

    return 0;
}
