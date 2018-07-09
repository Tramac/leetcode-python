#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* clone(TreeNode* root)
{
	if(root == NULL)
		return NULL;
	TreeNode *newroot = new TreeNode(root->val);
	newroot->left = clone(root->left);
	newroot->right = clone(root->right);
	return newroot;
}

vector<TreeNode *> generateTrees(int n)
{
	vector<TreeNode *> res(1, NULL);
	for (int i = 1; i <= n; ++i)
	{
		vector<TreeNode *> temp;
		for (int j = 0; j < res.size(); ++j)
		{
			TreeNode *oldroot = res[j];
			TreeNode *root = new TreeNode(i);
			TreeNode *target = clone(oldroot);
			root->left = target;
			temp.push_back(root);

			if(oldroot != NULL)
			{
				TreeNode *tempold = oldroot;
				while(tempold->right != NULL)
				{
					TreeNode *nonroot = new TreeNode(i);
					TreeNode *tright = tempold->right;
					tempold->right = nonroot;
					nonroot->left = tright;
					TreeNode *target = clone(oldroot);
					temp.push_back(target);
					tempold->right = tright;
					tempold = tempold->right;
				}
				tempold->right = new TreeNode(i);
				TreeNode *target = clone(oldroot);
				temp.push_back(target);
				tempold->right = NULL;
			}
		}
		res = temp;
	}
	return res;
}

int main()
{
	vector<TreeNode *> result = generateTrees(3);
	return 0;
}
