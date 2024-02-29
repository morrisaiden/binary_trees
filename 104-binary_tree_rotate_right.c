#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Description:
 *   This function performs a right rotation on a binary tree. A right rotation
 *   involves moving the left child of the given tree up to the root position,
 *   making the original root the right child of the new root, and adjusting
 *   pointers accordingly to maintain the binary tree structure.
 *
 * Return:
 *   - If the rotation is successful, the function returns a pointer to the new
 *     root node of the rotated tree.
 *   - If the given tree is NULL or its left child is NULL, indicating that a
 *     right rotation cannot be performed, the function returns NULL.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *piv, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	piv = tree->left;
	tmp = piv->right;
	piv->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = piv;
	piv->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = piv;
		else
			tmp->right = piv;
	}

	return (piv);
}
