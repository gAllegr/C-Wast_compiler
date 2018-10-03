#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

/* Create empty list */
List *list_new(void) {
    List *list = malloc(sizeof(List));
    list->size = 0;
    list->items = NULL;

    return list;
};

/* Return list length */
int list_length(List *list) {
    return list->size;
}

/* Add an item at the end of the list */
void list_append(List *list, void *item) {
    list->size++;
    list->items = realloc(list->items, list->size * sizeof(item));

    list->items[list->size - 1] = item;
}

/* Remove an item in a specific position */
void list_remove(List *list, int index)
{
    for(int i=index;i<list_length(list)-1;i++)
        list->items[i] = list->items[i+1];

    list->size--;
    list->items = realloc(list->items, list->size * sizeof(list->items[0]));
}

/* Get a specific element of the list */
void *list_get(List *list, int index) {
    return list->items[index];
}

/* Merge elements of two different lists */
List *list_merge(List *first_list, List *second_list) {
    if(second_list != NULL)
    {
        int size = list_length(second_list), i;
        for(i=0;i<size;i++)
        {
            void *item = list_get(second_list, i);
            list_append(first_list, item);
        } 
    }  

    return first_list;
}
