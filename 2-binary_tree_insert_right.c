#include "binary_trees.h"

/**
 * binary_tree_insert_right- Insets nodes on the right child and
 * takes two params:
 * @parent: A pointer to the parent node to which the new right
 * child node will be attached
 * @value: An integer representing the value to be stored in the new right
 * child node.
 *
 * Return: Pointer to new node
 *
 * if (parent->right != NULL) { ... }: This block of code checks if
 *  the parent already has a right child. If it does,
 *  it moves the existing right child to become the right child
 *  of the newly inserted node (new).
 *  This preserves the existing right subtree by attaching it to the newly
 *  inserted node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
