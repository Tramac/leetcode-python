#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(vector<int>& nums, int start, int end) {
    TreeNode* root = new TreeNode(0);
    int mid = (start + end) / 2;
    root->val = nums[mid];
    if (mid > start) {
        root->left = dfs(nums, start, mid - 1);
    }
    if (mid < end) {
        root->right = dfs(nums, mid + 1, end);
    }
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    vector<int> list;
    ListNode* node = head;
    while (node != NULL) {
        list.push_back(node->val);
        node = node->next;
    }
    TreeNode* root = dfs(list, 0, list.size() - 1);
    return root;
}

int main()
{
    ListNode* a = new ListNode(-10);
    ListNode* b = new ListNode(-3);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(5);
    ListNode* e = new ListNode(9);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    TreeNode* res = sortedListToBST(a);
    return 0;
}
