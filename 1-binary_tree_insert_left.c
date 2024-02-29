#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_insert_left - Inserts a node as the left-child of another node
* @parent: Pointer to the node to insert the left-child in
* @value: Value to store in the new node
*
* Return: Pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *new_node;

if (parent == NULL)
return (NULL);

new_node = malloc(sizeof(binary_tree_t));
if (new_node == NULL)
return (NULL);

new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;

if (parent->left != NULL)
{
new_node->left = parent->left;
parent->left->parent = new_node;
}
parent->left = new_node;

return (new_node);
}
/**
* binary_tree_nodes - Counts the nodes with at least one child in a binary tree
* @tree: Pointer to the root node of the tree to count the number of nodes
*
* Return: Number of nodes with at least one child in the binary tree
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
size_t nodes = 0;

if (tree == NULL)
return (0);

if (tree->left != NULL || tree->right != NULL)
nodes++;

nodes += binary_tree_nodes(tree->left);
nodes += binary_tree_nodes(tree->right);

return (nodes);
}

