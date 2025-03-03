#include "../../include/binary_tree.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief init a binary tree
 * 
 * @returns created binary tree
 * 
 * this functions allocates in memory a new binary tree
 * 
 * special cases:
 * 
 * 1. If initial node can't be allocated in memory, then this function will return a null pointer
 */
BinaryTreeNode *create_binary_tree_node()
{
  /**
   * 1) creates a new node and initialize it's values
   */
  BinaryTreeNode *new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));

  /**
   * Security measure: if node can't be allocated, then we must return null
   */
  if (new_node == NULL)
  {
    return NULL;
  }

  new_node->data = 0;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

/**
 * @brief creates a new node into a binary tree
 * 
 * @param head A pointer to pointer of the Binary Tree Head
 * @param data value of the new node
 * 
 * @returns amount of created nodes (in this case can be only 1 or 0)
 * 
 * This function allow user to allocate a new node into a binary tree
 * 
 * special cases:
 * 
 * 1. If given pointer to pointer is null, then this function will return 0
 * 
 * 2. If tree's head dosn't exists, then this function will allocate the new node as the tree's head
 * 
 * 3. If the new node can't be allocated, then this function will return 0
 */
int insert_binary_tree_node(BinaryTreeNode **head, int data)
{
  /**
   * Security measure: if given head is a null pointer, then we must return 0
   */
  if (head == NULL)
  {
    return 0;
  }

  /**
   * 1) Initializes a new node with given data
   */
  BinaryTreeNode *new_node = create_binary_tree_node();

  /**
   * Security measure: if this node can't be allocated, then we must return 0
   */
  if (new_node == NULL)
  {
    return 0;
  }

  new_node->data = data;


  /**
   * 2) If current head is a null pointer, then we must use this node to be the head of a new binary tree
   */
  if (*head == NULL)
  {
    *head = new_node;
    return 1;
  }

  /**
   * 3) Iterates over every child until we found the place where this node should be allocated
   */
  BinaryTreeNode *current_node = *head;

  while (1)
  {
    /**
     * If given data is greater than current node's data, then we must go to the right side of the current node
     */
    if (new_node->data >= current_node->data)
    {
      /**
       * If this node doesn't have a right side, then the new node will be the right side
       */
      if (current_node->right == NULL)
      {
        current_node->right = new_node;
        break;
      }

      /**
       * Change to the right side
       */
      current_node = current_node->right;
      continue;
    }

    /**
     * When the node isn't greater than current_node we must go to the left side
     */
    if (current_node->left == NULL)
    {
      current_node->left = new_node;
      break;
    }

    current_node = current_node->left;
  }

  return 1;
}

/**
 * @brief prints all the nodes from a binary search tree in inorder route
 * 
 * @param head Head Node
 * 
 * This function prints a binary search tree making use of inorder route
 */
static void auxiliar_print_binary_tree_inorder_route(BinaryTreeNode *head)
{
  /**
   * 1) If given head is null, we stop the calling of recursive function
   */
  if (head == NULL)
  {
    return;
  }

  /**
   * 2) Prints binary search tree giving priority to the left side, next, to the head
   * and finally, to the right side
   */
  auxiliar_print_binary_tree_inorder_route(head->left);
  printf("%d -> ", head->data);
  auxiliar_print_binary_tree_inorder_route(head->right);
}

void print_binary_tree_inorder_route(BinaryTreeNode *head) {
  if (head == NULL) {
    return;
  }

  auxiliar_print_binary_tree_inorder_route(head);
  printf("END\n");
}