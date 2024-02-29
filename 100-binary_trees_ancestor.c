#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * This function finds and returns the lowest common ancestor of the two
 * given nodes in a binary tree. If either of the nodes is NULL, or if the
 * nodes are the same, NULL is returned.
 *
 * Return: Pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor exists.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *fpn, *spn;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	fpn = first->parent, spn = second->parent;
	if (first == spn || !fpn || (!fpn->parent && spn))
		return (binary_trees_ancestor(first, fpn));
	else if (fpn == second || !spn || (!spn->parent && fpn))
		return (binary_trees_ancestor(fpn, second));
	return (binary_trees_ancestor(fpn, spn));
}
