#include "../../include/binary_tree.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

  while (current_node != NULL)
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

/**
 * @brief Prints binary in inorder
 * 
 * @param head Binary tree head
 * 
 * This function prints a binary tree following inorder route
 */
void print_binary_tree_inorder_route(BinaryTreeNode *head)
{
  if (head == NULL)
  {
    return;
  }

  auxiliar_print_binary_tree_inorder_route(head);
  printf("END\n");
}

/**
 * @brief Takes the maximum node from a Binary tree
 * 
 * @param node Target node
 * 
 * @returns Found Node
 */
BinaryTreeNode *find_binary_tree_max_node(BinaryTreeNode *node)
{
  if (node == NULL)
  {
    return NULL;
  }

  BinaryTreeNode *current_node = node;

  while (current_node->right != NULL)
  {
    current_node = current_node->right;
  }

  return current_node;
}

/**
 * @brief 
 */
BinaryTreeNode *find_binary_tree_node(BinaryTreeNode *node, int data)
{
  /**
   * Security measure: if given node is null then we must return null
   */
  if (node == NULL)
  {
    return NULL;
  }

  BinaryTreeNode *current_node = node;

  while (current_node != NULL)
  {
    if (data == current_node->data)
    {
      return current_node;
    }

    current_node = (data > current_node->data) ? current_node->right : current_node->left;
  }

  return NULL;
}

BinaryTreeNode *delete_binary_tree_node(BinaryTreeNode *head, int key)
{
  if (head == NULL)
    return head;

  if (key < head->data)
    head->left = delete_binary_tree_node(head->left, key);
  else if (key > head->data)
    head->right = delete_binary_tree_node(head->right, key);
  else
  {
    if (head->left == NULL && head->right == NULL)
    {
      free(head);
      return NULL;
    }

    else if (head->left == NULL)
    {
      BinaryTreeNode *temp = head->right;
      free(head);
      return temp;
    }
    else if (head->right == NULL)
    {
      BinaryTreeNode *temp = head->left;
      free(head);
      return temp;
    }
    BinaryTreeNode *temp = find_binary_tree_max_node(head->left);
    head->data = temp->data;
    head->left = delete_binary_tree_node(head->left, temp->data);
  }

  return head;
}
