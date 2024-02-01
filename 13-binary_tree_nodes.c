#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 * Return: If tree is NULL return 0, Otherwise return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_nodes = 0;

	if (tree == NULL)
		return (0);
	num_nodes += (tree->left || tree->right) ? 1 : 0;
	num_nodes += binary_tree_nodes(tree->left);
	num_nodes += binary_tree_nodes(tree->right);
	return (num_nodes);
}
