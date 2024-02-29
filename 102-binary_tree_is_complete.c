#include "binary_trees.h"

/**
 * create_node - Creates a new node for a level-order traversal queue.
 * @node: Pointer to the binary tree node to be stored in the new node.
 *
 * Return: A pointer to the newly created node, or NULL if memory allocation fails.
 *
 * Description: This function dynamically allocates memory for a new node
 *              in a level-order traversal queue. It stores the given binary
 *              tree node in the new node and initializes its next pointer to NULL.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a level-order traversal queue.
 * @head: Pointer to the head of the queue to be freed.
 *
 * Description: This function frees the memory allocated for all nodes
 *              in a level-order traversal queue, starting from the head.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes a new node onto a level-order traversal queue.
 * @node: Pointer to the binary tree node to be pushed onto the queue.
 * @head: Pointer to the head of the queue.
 * @tail: Pointer to the pointer to the tail of the queue.
 *
 * Description: This function creates a new node for the given binary tree
 *              node and pushes it onto the end of a level-order traversal queue.
 *              If memory allocation fails, it frees the entire queue and exits
 *              the program with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Removes the first node from a level-order traversal queue.
 * @head: Pointer to the pointer to the head of the queue.
 *
 * Description: This function removes the first node from a level-order
 *              traversal queue and updates the head pointer to point to
 *              the next node in the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
