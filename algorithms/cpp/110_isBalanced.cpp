#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root)
{
	if(root == NULL)
		return 0;
	return max(depth(root->left) + 1, depth(root->right) + 1);
}

bool isBalanced(TreeNode* root)
{
	if(root == NULL)
		return true;
	int left = depth(root->left);
	int right = depth(root->right);
	if(left - right > 1 || right - left > 1)
		return false;
	return isBalanced(root->left) && isBalanced(root->right);
}
