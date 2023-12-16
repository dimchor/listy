#include <stdio.h>

#include "../include/listy.h"

int main(void)
{
    puts("hello, world");

    LISTY_list_h list = LISTY_new_list(NULL, NULL, NULL, NULL);

    LISTY_delete_list(list);

    return 0;
}
