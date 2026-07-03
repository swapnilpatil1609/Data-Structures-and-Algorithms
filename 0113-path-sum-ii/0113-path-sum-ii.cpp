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
    void dfs(TreeNode* root,int currsum,int targetSum,vector<int> r,vector<vector<int>> &ans){
        if(root==NULL) return;
        currsum+=root->val;
        r.push_back(root->val);
        if(root->left==NULL && root->right==NULL && currsum==targetSum){
            ans.push_back(r);
        }
        dfs(root->left,currsum,targetSum,r,ans);
        dfs(root->right,currsum,targetSum,r,ans);
       
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> r;
        dfs(root,0,targetSum,r,ans);
        return ans;
    }
};