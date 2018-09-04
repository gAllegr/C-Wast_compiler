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

/* Deallocate list memory */
void list_free(List *list) {
    if (list->items != NULL) {
        free(list->items);
    }
    free(list);
}

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

/* Insert an item as the first element in the list */
void list_push(List *list, void *item) {
    list->size++;

    void **new_items = malloc(list->size * sizeof(item));
    memcpy(new_items + 1, list->items, (list->size - 1) * sizeof(item));

    if (list->items != NULL) {
        free(list->items);
    }
    list->items = new_items;

    list->items[0] = item;
}

/* Remove the last item from the list and return it */
void *list_pop(List *list) {
    void *value = list_get(list, list->size - 1);

    list->size--;
    list->items = realloc(list->items, list->size * sizeof(value));

    return value;
}

/* Get a specific element of the list */
void *list_get(List *list, int index) {
    return list->items[index];
}

List *list_merge(List *first_list, List *second_list) {
    int size = list_length(second_list), i;
    for(i=0;i<size;i++)
    {
        void *item = list_get(second_list, i);
        list_append(first_list, item);
    }

    return first_list;
}
