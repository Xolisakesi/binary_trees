#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/**
* struct queue_s - Queue structure
* @item: Pointer to the data stored in the queue
* @next: Pointer to the next node in the queue
*/
typedef struct queue_s
{
void *item;
struct queue_s *next;
} queue_t;

/**
* queue_push - Pushes an item onto the queue.
* @queue: Pointer to the pointer to the head of the queue
* @item: Pointer to the item to be pushed onto the queue
*/
void queue_push(queue_t **queue, void *item)
{
queue_t *new_node = malloc(sizeof(queue_t));
if (!new_node)
return;

new_node->item = item;
new_node->next = NULL;

if (!*queue)
{
*queue = new_node;
return;
}

queue_t *current = *queue;
while (current->next)
current = current->next;

current->next = new_node;
}

/**
* queue_pop - Pops an item from the queue.
* @queue: Pointer to the pointer to the head of the queue
*
* Return: Pointer to the popped item, or NULL if the queue is empty
*/
void *queue_pop(queue_t **queue)
{
if (!*queue)
return (NULL);

queue_t *temp = *queue;
void *item = temp->item;
*queue = temp->next;
free(temp);
return (item);
}

/**
* queue_empty - Checks if the queue is empty.
* @queue: Pointer to the head of the queue
*
* Return: 1 if the queue is empty, 0 otherwise
*/
int queue_empty(const queue_t *queue)
{
return (queue == NULL);
}

/**
* queue_delete - Deletes the queue and frees its memory.
* @queue: Pointer to the head of the queue
*/
void queue_delete(queue_t *queue)
{
queue_t *current = queue;
while (current)
{
queue_t *next = current->next;
free(current);
current = next;
}
}

#endif /* QUEUE_H */

