#include "binary_trees.h"

/**
* bst_insert - Inserts a value in a Binary Search Tree (BST).
* @tree: A double pointer to the root node of the BST to insert the value.
* @value: The value to store in the node to be inserted.
*
* Return: A pointer to the created node, or NULL on failure.
*/
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t  *current;

if (!tree)
return (NULL);

if (!*tree)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

current = *tree;
while (current)
{
if (value == current->n)
return (NULL);
if (value < current->n)
{
if (!current->left)
{
current->left = binary_tree_node(current, value);
return (current->left);
}
current = current->left;
}
else
{
if (!current->right)
{
current->right = binary_tree_node(current, value);
return (current->right);
}
current = current->right;
}
}

return (NULL);
}

