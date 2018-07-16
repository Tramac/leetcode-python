#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeCore(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd){
	int rootValue = preorder[preStart];
	TreeNode *root = new TreeNode(rootValue);
	if(preStart == preEnd){
		if(inStart == inEnd && preorder[preStart] == inorder[inStart]){
			return root;
		}
		else
			throw std::exception("Invalid input.");
	}

	int rootInorder = inStart;
	while(rootInorder <= inEnd && inorder[rootInorder] != rootValue){
		++rootInorder;
	}
	if(rootInorder == inEnd && inorder[rootInorder] != rootValue){
		throw std::exception("Invalid input.");
	}
	int leftLength = rootInorder - inStart;
	if(leftLength > 0){
		root->left = buildTreeCore(preorder, preStart + 1, preStart + leftLength, inorder, inStart, inStart + leftLength - 1);
	}
	if(leftLength < preEnd - preStart){
		root->right = buildTreeCore(preorder, preStart + leftLength + 1, preEnd, inorder, inStart + leftLength + 1, inEnd);
	}
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
	if(preorder.size() == 0 || inorder.size() == 0)
		return NULL;
	return buildTreeCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}
