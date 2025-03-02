#include "../../include/linked_list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief create a node for a linked list
 *
 * @returns pointer for created node
 *
 * This function create a node for a linked list and allocates it
 * into heap
 */
LinkedListNode *create_linked_list_node()
{
  LinkedListNode *new_node = (LinkedListNode *)malloc(sizeof(LinkedListNode));

  /**
   * Security measure: returns NULL if malloc can't allocate this node
   */
  if (new_node == NULL)
  {
    return NULL;
  }

  new_node->next = NULL;
  new_node->data = 0;

  return new_node;
}

/**
 * @brief get the last node of a linked list
 *
 * @param head the head node of the linked list
 *
 * @return last node
 *
 * This function takes the Head Node and iterates over every references node
 * until we found the last node
 *
 * Special cases:
 *
 * 1. If head node is a null pointer this function will return NULL
 * 2. If head node is already the last node this function will return the head node
 */
LinkedListNode *take_last_from_linked_list(LinkedListNode *head)
{
  /**
   * Security measure: returns NULL if head is a null pointer
   */
  if (head == NULL)
  {
    return NULL;
  }

  /**
   * We must return head node if it's already the last from linked list
   */
  if (head->next == NULL)
  {
    return head;
  }

  LinkedListNode *current_node = head;

  /**
   * 1) Iterates over every child until we found last node
   */
  while (current_node->next != NULL)
  {
    current_node = current_node->next;
  }

  return current_node;
}

/**
 * @brief takes penultimate node from a linked list
 *
 * @param head Head Node
 *
 * @returns Penultimate node from the linked list
 *
 * This function takes a Head Node and returns the node that goes before last node
 *
 * Special cases
 *
 * 1. if Head Node is null then this function will return NULL
 * 2. if Head Node is already the last node then function will also return NULL
 */
LinkedListNode *take_penultimate_from_linked_list(LinkedListNode *head)
{
  /**
   * Security measure: if head node is null, we must return null
   */
  if (head == NULL)
  {
    return NULL;
  }

  /**
   * Security measure: if head node is already the last node, then doesn't makes sense
   * that this function returns head node because there doesn't exists a node that goes
   * before last node in linked list
   */
  if (head->next == NULL)
  {
    return NULL;
  }

  LinkedListNode *current_node = head;

  /**
   * !. We iterates over all the node until we found the node that goes before
   * last node in linked list
   */
  while (current_node->next->next == NULL)
  {
    current_node = current_node->next;
  }

  return current_node;
}

/**
 * @brief deletes last node from a linked list
 *
 * @param head Head Node
 *
 * @returns amount of affected nodes during the operation
 *
 * This function takes the Head Node of a linked list and deletes the last node
 *
 * Special cases:
 *
 * 1. if Head Node is a null pointer, then function will return 0 affected rows
 *
 * 2. if Head Node is the last node from linked list, then function will free the memory of the
 * Head Node and will make variable a NULL pointer after freeing the memory
 */
int pop_linked_list(LinkedListNode **head)
{
  /**
   * Security measure: if Head Node is a null pointer, we must return 0
   */
  if (*head == NULL)
  {
    return 0;
  }

  /**
   * Security measure: if Head Node is last node from linked list, we must free
   * the Head Node and return 1
   */
  if ((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;

    return 1;
  }

  /**
   * 1) We takes penultimate node from linked list, next we free the memory of the
   * last node
   */
  LinkedListNode *penultimate_node = take_penultimate_from_linked_list(*head);

  free(penultimate_node->next);
  penultimate_node->next = NULL;

  return 1;
}

/**
 * @brief deletes first node from a linked list
 *
 * @param head Head Node
 *
 * @return amount of affected nodes during the operation
 *
 * This function takes the Head Node of a linked list and deletes the first node
 *
 * Special cases:
 *
 * 1. if Head Node is a null pointer, then function will return 0 affected rows
 *
 * 2. if Head Node is the last node from linked list, then function will free the memory of the
 * Head Node and will make variable a NULL pointer after freeing the memory
 */
int shift_linked_list(LinkedListNode **head)
{
  /**
   * Security measure: if Head Node is a null pointer, we must return NULL
   */
  if (*head == NULL)
  {
    return 0;
  }

  /**
   * Security measure: if Head Node is already last node, we must free the Head Node
   * and return 1
   */
  if ((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;

    return 1;
  }

  LinkedListNode *next_node = (*head)->next;

  /**
   * 1) We must free the Head Node and make the variable to point to the next Node in Linked List
   */
  free(*head);
  *head = next_node;

  return 1;
}

/**
 * @brief push a new node at the end of a linked list
 *
 * @param head Head Node
 * @param data value that new node will have
 *
 * @returns amount of created nodes during the operation
 *
 * This function takes the head node and creates a node with the given data
 *
 * Special cases:
 *
 * 1. if head variable is a null pointer, then this function will return 0
 *
 * 2. If the new node can't be allocated, then this function will return 0
 *
 * 3. If Head Node is a null pointer, this function will take the given variable and will make
 * it to point to the new node
 */
int push_linked_list(LinkedListNode **head, int data)
{
  /**
   * Security measure: if Head Node is a null pointer, we must return 0;
   */
  if (head == NULL)
  {
    return 0;
  }

  /**
   * 1) Creates a new node and initialize it's data
   */
  LinkedListNode *new_node = create_linked_list_node();

  /**
   * Security measure: if new node is a null pointer we must return 0
   */
  if (new_node == NULL)
  {
    return 0;
  }

  new_node->data = data;

  /**
   * Security measure: if head node is a null pointer, we must make variable to point to the new
   * node and return 1
   */
  if (*head == NULL)
  {
    *head = new_node;
    return 1;
  }

  /**
   * 2) Takes last node from linked list and makes it pointer to reference the new node
   */
  LinkedListNode *last_node = take_last_from_linked_list(*head);

  last_node->next = new_node;

  return 1;
}

/**
 * @brief push a new node at the beginning of a linked list
 *
 * @param head Head Node
 * @param data value that new node will have
 *
 * @returns amount of created nodes during the operation
 *
 * This function takes the head node and creates a node with the given data
 *
 * Special cases:
 *
 * 1. if head variable is a null pointer, then this function will return 0
 *
 * 2. If the new node can't be allocated, then this function will return 0
 *
 * 3. If Head Node is a null pointer, this function will take the given variable and will make
 * it to point to the new node
*/
int append_linked_list(LinkedListNode **head, int data)
{
  /**
   * Security measure: if Head Node is a null pointer, we must return 0;
   */
  if (head == NULL)
  {
    return 0;
  }

  /**
   * 1) Creates a new node and initialize it's data
   */
  LinkedListNode *new_node = create_linked_list_node();

  /**
   * Security measure: if new node is a null pointer we must return 0
   */
  if (new_node == NULL)
  {
    return 0;
  }

  new_node->data = data;

  /**
   * Security measure: if head node is a null pointer, we must make variable to point to the new
   * node and return 1
   */
  if (*head == NULL)
  {
    *head = new_node;
    return 1;
  }

  /**
   * 2. We have to make the new node to point to Head Node, and the given variable to point to the
   * new node
   */
  new_node->next = *head;

  *head = new_node;

  return 1;
}

/**
 * @brief clean a linked list
 * 
 * @param head Head Node
 * 
 * @returns amount of affected nodes during the operation
 * 
 * This function takes the Head Node from a linked list and free all the nodes
 * 
 * Special cases:
 * 
 * 1. if Head Node is a null pointer, then this function will return 0
 */
int free_linked_list(LinkedListNode *head) {
  /**
   * Security measure: if variable is a null pointer, we must return 0
   */
  if (head == NULL) {
    return 0;
  }

  /**
   * 1. Shift all nodes until the list is empty
   */
  int deleted_nodes = 0;

  while (shift_linked_list(&head) == 1) {
    deleted_nodes++;
  }

  return deleted_nodes;
}

/**
 * @brief prints into console all the nodes of a linked list
 * 
 * @param head Head Node
 * 
 * This function prints all the nodes of a linked list in the following format:
 * 
 * node1 -> node2 -> node3 -> NULL
 * 
 * All printed items are the data store into node
 * 
 * Special cases:
 * 
 * 1. If Head Node is a null pointer, then this function will just print "NULL"
 */
void print_linked_list(LinkedListNode *head) {
  /**
   * Security measure: if Head Node is a null pointer, this function will print NULL
   */
  if (head == NULL) {
    printf("NULL");
  }

  /**
   * 1) Iterates over all the nodes and print the value that every node stores
   */
  LinkedListNode* current_node = head;

  while (current_node->next != NULL) {
    printf("%d -> ", current_node->data);
    current_node = current_node->next;
  }

  /**
   * 2) Prints null at the end of the printf because last pointer is a null pointer
   */
  printf("NULL");
}