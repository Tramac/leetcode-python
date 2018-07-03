#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void binaryTreePaths(vector<string>& paths, TreeNode* root, string path)
{
	if (root->left == NULL && root->right == NULL)
	{
		paths.push_back(path);
		return;
	}
	if(root->left)
		binaryTreePaths(paths, root->left, path + "->" + to_string(root->left->val));
	if(root->right)
		binaryTreePaths(paths, root->right, path + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode *root)
{
	vector<string> paths;
	if(root == NULL)
		return paths;
	binaryTreePaths(paths, root, to_string(root->val));
	return paths;
}
