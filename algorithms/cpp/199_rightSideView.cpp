#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, int layer, vector<int>& res) {
	if (!root)
		return;
	if (layer >= res.size())
		res.push_back(root->val);
	dfs(root->right, layer + 1, res);
	dfs(root->left, layer + 1, res);
}

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	dfs(root, 0, res);
	return res;
}
