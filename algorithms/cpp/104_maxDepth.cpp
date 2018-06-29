#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

int maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;
    int depth = 1;
    return max(maxDepth(root->left) + depth, maxDepth(root->right) + depth);
}
