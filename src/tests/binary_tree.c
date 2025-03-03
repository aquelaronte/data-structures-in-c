#include "binary_tree.h"

#include <stdio.h>
#include <assert.h>

void test_inorder_print_tree()
{
  printf("Testing inorder print\n");
  BinaryTreeNode *head = create_binary_tree_node();
  head->data = 15;

  insert_binary_tree_node(&head, 10);
  insert_binary_tree_node(&head, 20);
  insert_binary_tree_node(&head, 30);
  insert_binary_tree_node(&head, 9);
  insert_binary_tree_node(&head, 18);

  assert(head->data == 15);
  assert(head->left->data == 10);
  assert(head->left->left->data == 9);
  assert(head->right->data == 20);
  assert(head->right->left->data == 18);
  assert(head->right->right->data == 30);

  print_binary_tree_inorder_route(head);

  printf("\nInorder print works!\n");

  // This three may look like this:
  /**
   *        15
   *      10  20
   *     9   18 30
   */
}

void test_binary_tree()
{
  test_inorder_print_tree();
}