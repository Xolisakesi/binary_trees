#include "binary_trees.h"

/**
* binary_tree_balance - Measures the balance factor of a binary tree.
* @tree: A pointer to the root node of the tree to measure the balance factor.
*
* Return: If tree is NULL, return 0, else return balance factor.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
if (tree)
return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

return (0);
}

/**
* binary_tree_height - Measures the height of a binary tree.
* @tree: A pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree)
{
size_t left_height = 0, right_height = 0;

left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
return ((left_height > right_height) ? left_height : right_height);
}
return (0);
}

/**
* binary_tree_is_perfect - Checks if a binary tree is perfect.
* @tree: A pointer to the root node of the tree to check.
*
* Return: If the tree is NULL, return 0.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

if (binary_tree_balance(tree) != 0)
return (0);

if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
return (0);

return (1);
}

