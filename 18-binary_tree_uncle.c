#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: Pointer to the node to find the uncle for.
 *
 * This function returns a pointer to the uncle node of the given node
 * in the binary tree. If the node is NULL, has no parent, or the parent
 * has no parent (grandparent), NULL is returned. If the parent is the
 * left child of its parent (grandparent), the right child of the
 * grandparent is returned; otherwise, the left child is returned.
 *
 * Return: Pointer to the uncle node, or NULL if no uncle exists.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
            node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
