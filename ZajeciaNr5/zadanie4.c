#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void addFirst(node_t **head, int value){

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = value;
    new_node->next = *head;
    *head = new_node;
}

void pop(node_t **head){

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeLast(node_t **head){

    node_t *curr = *head;

    while(curr->next->next != NULL){
        curr = curr->next;
    }

    free(curr->next);
    curr->next = NULL;
}

void removeByIndex(node_t **head, int index){

    node_t *curr = *head;

    for(int i = 0; i < index - 1; i++){
        curr = curr->next;
    }
    node_t *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}


int main(){
    node_t *head = NULL;
    
    addFirst(&head, 0);
    addFirst(&head, 1);
    addFirst(&head, 2);
    addFirst(&head, 3);
    addFirst(&head, 4);
    addFirst(&head, 5);
    removeByIndex(&head, 4);

    node_t *curr = head;

    while(curr != NULL){
        printf("%d ->", curr->val);
        curr = curr->next;
    }
}
