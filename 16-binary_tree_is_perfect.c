#include "binary_trees.h"

int binary_tree_Height(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, int height, int level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL return 0, Otherwise return height.
 */
int binary_tree_Height(const binary_tree_t *tree)
{
	int left_height = 0 , right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = tree->left ? binary_tree_Height(tree->left) + 1 : 0;
	right_height = tree->right ? binary_tree_Height(tree->right) + 1 : 0;
	return ((left_height > right_height) ? left_height : right_height);
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @height: The height of the binary tree.
 * @level: Level of current node.
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree, int height, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (height == level + 1);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, height, level + 1) &&
		is_perfect_recursive(tree->right, height, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or not perfect - 0, Otherwise - 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	height = binary_tree_Height(tree);
	return (is_perfect_recursive(tree, height, 0));
}
