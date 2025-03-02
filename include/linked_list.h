#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Main structure for linked list
typedef struct LinkedListNode
{
  int data;
  struct LinkedListNode *next;
} LinkedListNode;

// Main functions
LinkedListNode *create_linked_list_node();
int pop_linked_list(LinkedListNode **head);
int shift_linked_list(LinkedListNode **head);
int push_linked_list(LinkedListNode **head, int data);
int append_linked_list(LinkedListNode **head, int data);
int free_linked_list(LinkedListNode *head);
void print_linked_list(LinkedListNode *head);

// Auxiliar functions
LinkedListNode *take_last_from_linked_list(LinkedListNode *head);
LinkedListNode *take_penultimate_from_linked_list(LinkedListNode *head);

#endif