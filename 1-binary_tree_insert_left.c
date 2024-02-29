#include "binary_trees.h"
/**
 * binary_tree_insert_left - Inserts a node as the left child of a given node.
 * @parent: A pointer to the parent node to insert the left child into.
 * @value: The integer value to store in the new left child node.
 *
 * Return: If 'parent' is NULL or memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the newly inserted left child node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
