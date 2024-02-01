#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or is not full return 0, Otherwise return 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l_full, r_full;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
	{
		l_full = binary_tree_is_full(tree->left);
		r_full = binary_tree_is_full(tree->right);

		return (l_full && r_full);
	}
	return (0);
}
