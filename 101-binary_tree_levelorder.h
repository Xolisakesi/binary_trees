/**
 * struct node_s - Singly linked list node
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next node
 */
typedef struct node_s
{
    const binary_tree_t *node;
    struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

