#include "binary_trees.h"

/**
* binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
* @first: A pointer to the first node.
* @second: A pointer to the second node.
*
* Return: A pointer to the lowest common ancestor node, or NULL if not found.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
const binary_tree_t *temp = NULL;

if (!first || !second)
return (NULL);

temp = second;
while (first)
{
while (temp)
{
if (temp == first)
return ((binary_tree_t *)first);
temp = temp->parent;
}
temp = second;
first = first->parent;
}
return (NULL);
}

