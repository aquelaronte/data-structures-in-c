#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef enum BinaryTreeNodeComesFrom
{
  LEFT,
  RIGHT
} BinaryTreeNodeComesFrom;

typedef struct BinaryTreeNode
{
  int data;
  struct BinaryTreeNode *left;
  struct BinaryTreeNode *right;
} BinaryTreeNode;

// Main functions
BinaryTreeNode *create_binary_tree_node();
int insert_binary_tree_node(BinaryTreeNode **head, int data);
void print_binary_tree_inorder_route(BinaryTreeNode *head);
BinaryTreeNode * delete_binary_tree_node(BinaryTreeNode *head, int data);
BinaryTreeNode *search_binary_tree_node(BinaryTreeNode *head, int data);

// Test function
void test_binary_tree();

#endif