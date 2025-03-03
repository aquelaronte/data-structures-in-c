#include <assert.h>
#include <stdio.h>
#include "linked_list.h"

static void test_create_node()
{
  LinkedListNode *head = create_linked_list_node();
  printf("Testing Create Node\n");

  print_linked_list(head);

  assert(head != NULL);

  printf("Create node works!\n\n");
  free_linked_list(&head);
}

static void test_push_nodes()
{
  LinkedListNode *head = create_linked_list_node();
  printf("Testing Push Nodes\n");

  append_linked_list(&head, -1);
  push_linked_list(&head, 1);
  push_linked_list(&head, 2);
  push_linked_list(&head, 3);
  push_linked_list(&head, 4);
  push_linked_list(&head, 5);
  push_linked_list(&head, 6);
  // Current list is [-1, 0, 1, 2, 3, 4, 5, 6]

  print_linked_list(head);

  assert(head->data == -1);
  assert(take_last_from_linked_list(head)->data == 6);
  assert(take_penultimate_from_linked_list(head)->data == 5);

  printf("Push nodes works!\n\n");
  free_linked_list(&head);
}

static void test_delete_nodes()
{
  LinkedListNode *head = create_linked_list_node();
  printf("Testing Nodes Deletion\n");

  append_linked_list(&head, -1);
  push_linked_list(&head, 1);
  push_linked_list(&head, 2);
  push_linked_list(&head, 3);
  push_linked_list(&head, 4);
  push_linked_list(&head, 5);
  push_linked_list(&head, 6);
  // Current list is [-1, 0, 1, 2, 3, 4, 5, 6]

  shift_linked_list(&head);
  pop_linked_list(&head);
  pop_linked_list(&head);
  pop_linked_list(&head);
  pop_linked_list(&head);
  pop_linked_list(&head);
  // Current list is [0, 1]

  print_linked_list(head);

  assert(head->next != NULL);
  assert(head->data == 0);
  assert(head->next->data == 1);
  assert(head->next->next == NULL);

  printf("Nodes deletion works!\n\n");
  free_linked_list(&head);
}

void test_linked_list()
{
  test_create_node();
  test_push_nodes();
  test_delete_nodes();
}