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
    void f(TreeNode* root,vector<int> &in){
        if(root==NULL) return;
        f(root->left,in);
        in.push_back(root->val);
        f(root->right,in);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> in;
        int sum = 0;
        f(root,in);
        for(int i=0;i<in.size();i++){
            if(in[i]>=low && in[i]<=high) sum+=in[i];
        }
        return sum;
    }
};