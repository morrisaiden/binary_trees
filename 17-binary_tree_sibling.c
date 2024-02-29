#include "binary_trees.h"
/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: Pointer to the node to find the sibling for.
 *
 * This function returns a pointer to the sibling node of the given node
 * in the binary tree. If the node is NULL or has no parent, or if the
 * parent has no other child, NULL is returned.
 *
 * Return: Pointer to the sibling node, or NULL if no sibling exists.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
