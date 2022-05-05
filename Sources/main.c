#include <stdio.h>
#include <string.h>

struct Node {
    int data_node;
    struct Node *next;
};

struct List {
    struct Node *size;
    struct Node *first;
};

void insert_start (struct List *list, int num) {
    struct Node *new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data_node = num;
    new_node->next = list->first;
    list->first = new_node->data_node;
}

void show_list(struct List *list) {
    struct Node *index;
    printf(list->first);
    for(index = list->first; index!=NULL; index = index->next){
        printf("%d \n", index->data_node);
    }
}

void verify_empty_list(struct List *list) {
    list->size == NULL;
};

void main() {
    struct List list;
    int value;

    printf("insert a value: ");
    scanf("%d", &value);

    insert_start(&list, value);

    if(verify_empty_list(&list)){
        printf("Empty list.");
    } else {
        show_list(&list);
    }

    return 0;
};
