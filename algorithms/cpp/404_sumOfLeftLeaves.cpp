#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root)
{
	if(root == NULL)
		return 0;
	if(root->left != NULL)
	{    
		if(root->left->left == NULL && root->left->right == NULL)
		    return root->left->val + sumOfLeftLeaves(root->right);
	    else
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
	else
		return sumOfLeftLeaves(root->right);
}
