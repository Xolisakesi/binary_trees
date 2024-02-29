#include "binary_trees.h"
#include "queue.h"

/**
* binary_tree_levelorder - Traverse a binary tree using level-order traversal.
* @tree: A pointer to the root node of the tree to traverse.
* @func: A pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (!tree || !func)
return;

queue_t *queue = NULL;
const binary_tree_t *current = NULL;

queue_push(&queue, (void *)tree);

while (!queue_empty(queue))
{
current = (const binary_tree_t *)queue_pop(&queue);
func(current->n);

if (current->left)
queue_push(&queue, (void *)current->left);
if (current->right)
queue_push(&queue, (void *)current->right);
}

queue_delete(queue);
}

