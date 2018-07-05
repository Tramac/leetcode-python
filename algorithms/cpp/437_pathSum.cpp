#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, int& count, int sum)
{
	if(root == NULL)
		return;
	if(root->val == sum)
		count++;
	dfs(root->left, count, sum - root->val);
	dfs(root->right, count, sum - root->val);
}

int pathSum(TreeNode* root, int sum)
{
	if(root == NULL)
		return 0;
	int count = 0;
	dfs(root, count, sum);
	return count + pathSum(root->left, sum) + pathSum(root->right, sum);
}
