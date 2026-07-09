/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(vector<int> &pre , TreeNode* root){
        if(root==NULL) return;
        pre.push_back(root->val);
        fun(pre,root->left);
        fun(pre,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> pre;
        fun(pre,root);
        sort(pre.begin(),pre.end());
        return pre[k-1];
    }
};