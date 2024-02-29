#include "binary_trees.h"

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

