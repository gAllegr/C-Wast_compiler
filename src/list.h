#ifndef LIST_H
#define LIST_H

/* === List definition === */
typedef struct List {
    int size;
    void **items;
} List;

/* === List functions === */
List *list_new(void);
int list_length(List *list);
void list_free(List *list);
void list_append(List *list, void *item);
void list_push(List *list, void *item);
void *list_pop(List *list);
void *list_get(List *list, int index);

#endif