#include "binary_trees.h"
#include <limits.h>
/**
* is_bst_util - Checks if a binary tree is a valid BST.
* @tree: A pointer to the root node of the tree to check.
* @min: The minimum value allowed in this subtree.
* @max: The maximum value allowed in this subtree.
*
* Return: 1 if the tree is a valid BST, otherwise 0.
*/
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
if (!tree)
return (1);

if (tree->n < min || tree->n > max)
return (0);

return (is_bst_util(tree->left, min, tree->n - 1) &&
is_bst_util(tree->right, tree->n + 1, max));
}

/**
* binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
* @tree: A pointer to the root node of the tree to check.
*
* Return: 1 if the tree is a valid BST, otherwise 0.
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
if (!tree)
return (0);

return (is_bst_util(tree, INT_MIN, INT_MAX));
}

