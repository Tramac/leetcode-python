#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void FindPath(TreeNode* root, int sum, int currentSum, vector<int>& path, vector<vector<int> >& paths){
	currentSum += root->val;
	path.push_back(root->val);

	bool isLeaf = root->left == NULL && root->right == NULL;
	if(currentSum == sum && isLeaf){
		paths.push_back(path);
	}
	if(root->left != NULL)
		FindPath(root->left, sum, currentSum, path, paths);
	if(root->right != NULL)
		FindPath(root->right, sum, currentSum, path, paths);
	path.pop_back();
}

vector<vector<int> > pathSum(TreeNode* root, int sum){
	vector<vector<int>> paths;
	if(root == NULL)
		return paths;
	vector<int> path;
	int currentSum = 0;
	FindPath(root, sum, currentSum, path, paths);
	return paths;
}
