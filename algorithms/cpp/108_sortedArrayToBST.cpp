#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums)
{
	if(nums.size() == 0)
		return NULL;
	if(nums.size() == 1)
		return new TreeNode(nums[0]);
	int mid = nums.size() / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	vector<int>::iterator start = nums.begin();
	vector<int>::iterator end = nums.end();
	if(mid > 0)
	{
		vector<int>::iterator left_end = start + mid;
		vector<int> left_nums(start, left_end);
		root->left = sortedArrayToBST(left_nums);
	}
	if(mid < nums.size())
	{
		vector<int>::iterator right_start = start + mid + 1;
		vector<int> right_nums(right_start, end);
		root->right = sortedArrayToBST(right_nums);
	}
	return root;
}
int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	TreeNode *root = sortedArrayToBST(nums);
	return 0;
}
