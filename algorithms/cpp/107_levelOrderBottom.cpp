#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
}

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	queue<TreeNode *> nodes;
	vector<vector<int>> results;
	stack<vector<int>> out;
	if (root)
	{
		nodes.push(root);
		while(nodes.size())
		{
			int len = nodes.size();
			vector<int> temp;
			for (int i = 0; i < len; ++i)
			{
				TreeNode *node = nodes.front();
				nodes.pop();
				temp.push_back(node->val);
				if(node->left)
					nodes.push(node->left);
				if(node->right)
					nodes.push(node->right);
			}
			out.push(temp);
		}
		int l = out.size();
		while(l>0)
		{
			results.push_back(out.top());
			out.pop();
			l--;
		}
	}
	return results;
}
