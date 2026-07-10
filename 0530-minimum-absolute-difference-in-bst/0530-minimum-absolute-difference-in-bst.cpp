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
    void fun(vector<int> &in,TreeNode* root){
        if(root==NULL) return;
        fun(in,root->left);
        in.push_back(root->val);
        fun(in,root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> in;
        fun(in,root);
        int ans = INT_MAX;
        for(int i=1;i<in.size();i++){
            ans = min(ans,in[i]-in[i-1]);
        }
        return ans;
    }
};