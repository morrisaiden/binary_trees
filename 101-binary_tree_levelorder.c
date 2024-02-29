#include "binary_trees.h"

/**
 * create_node - Creates a new node for a level-order traversal queue.
 * @node: Pointer to the binary tree node to store in the new queue node.
 *
 * This function allocates memory for a new node of type `levelorder_queue_t`
 * and initializes it with the provided binary tree node. It returns a pointer
 * to the newly created node.
 *
 * Return: Pointer to the newly created node, or NULL if memory allocation fails.
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
 * free_queue - Frees the memory allocated for a level-order traversal queue.
 * @head: Pointer to the head of the queue.
 *
 * This function iterates through the level-order traversal queue and frees
 * the memory allocated for each node. It starts from the head of the queue
 * and traverses it until the end, freeing each node as it goes.
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
 * pint_push - Pushes the children of a node into a level-order traversal queue.
 * @node: Pointer to the current node.
 * @head: Pointer to the head of the queue.
 * @tail: Pointer to the pointer to the tail of the queue.
 * @func: Pointer to the function to print the node's value.
 *
 * This function prints the value of the current node using the provided
 * function pointer, and then pushes its left and right children into the
 * level-order traversal queue.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Removes the head node from a level-order traversal queue.
 * @head: Pointer to the pointer to the head of the queue.
 *
 * This function removes the head node from the level-order traversal queue.
 * It updates the head pointer to point to the next node in the queue and
 * frees the memory allocated for the removed node.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to the function to be called on each node's value.
 *
 * This function performs a level-order traversal on the binary tree,
 * starting from the root node. For each node visited, the specified
 * function is called to process its value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
