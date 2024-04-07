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


int main(){
    node_t *head = NULL;
    
    addFirst(&head, 1);
    addFirst(&head, 2);
    addFirst(&head, 3);
    removeLast(&head);

    node_t *curr = head;

    while(curr != NULL){
        printf("%d ->", curr->val);
        curr = curr->next;
    }
}
