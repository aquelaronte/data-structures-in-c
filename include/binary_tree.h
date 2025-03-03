#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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

// Test function
void test_binary_tree();

#endif