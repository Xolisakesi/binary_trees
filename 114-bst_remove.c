#include "binary_trees.h"

/**
* bst_find_successor - Find the inorder successor of a node
* @node: Pointer to the node
*
* Return: Pointer to the inorder successor node
*/
bst_t *bst_find_successor(bst_t *node)
{
bst_t *current = node;

while (current && current->left != NULL)
current = current->left;

return current;
}

/**
* bst_remove - Removes a node from a Binary Search Tree
* @root: Pointer to the root node of the tree where you will remove a node
* @value: Value to remove in the tree
*
* Return: Pointer to the new root node of the tree after removing the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
if (root == NULL)
return NULL;

if (value < root->n)
root->left = bst_remove(root->left, value);
else if (value > root->n)
root->right = bst_remove(root->right, value);
else
{
if (root->left == NULL)
{
bst_t *temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
bst_t *temp = root->left;
free(root);
return temp;
}

bst_t *temp = bst_find_successor(root->right);
root->n = temp->n;
root->right = bst_remove(root->right, temp->n);
}

return root;
}

