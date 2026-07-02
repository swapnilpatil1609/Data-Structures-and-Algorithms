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

// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right==NULL) return 1;
        int lh = minDepth(root->left);
        if(lh==NULL) lh=INT_MAX;
        int rh = minDepth(root->right);
        if(rh==NULL) rh=INT_MAX;
        return 1 + min(lh,rh);
    }
};