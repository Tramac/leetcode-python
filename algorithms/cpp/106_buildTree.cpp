#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeCore(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
	int rootValue = postorder[postEnd];
	TreeNode *root = new TreeNode(rootValue);
	if(inStart == inEnd){
		if(postStart == postEnd && inorder[inStart] == postorder[postStart])
			return root;
		else
			throw std::exception("Invalid input.");
	}
	int rootInorder = inStart;
	while(rootInorder <= inEnd && inorder[rootInorder] != rootValue)
		rootInorder++;
	if(rootInorder == inEnd && inorder[rootInorder] != rootValue)
	    throw std::exception("Invalid input.");
	int leftLength = rootInorder - inStart;
	if(leftLength > 0){
		root->left = buildTreeCore(inorder, inStart, inStart + leftLength - 1, postorder, postStart, postStart + leftLength - 1);
	}
	if(leftLength < inEnd - inStart){
		root->right = buildTreeCore(inorder, inStart + leftLength + 1, inEnd, postorder, postStart + leftLength, postEnd - 1);
	}
	return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
	if(inorder.size() == 0 || postorder.size() == 0)
		return NULL;
	return buildTreeCore(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
