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
unordered_map<int,int> mp;
    void helper(TreeNode* root){
        mp[root->val]++;
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        int mx=0;
        vector<int> ans;
        for(auto it:mp){
            mx=max(mx,it.second);
        }
        for(auto it:mp){
            if(it.second==mx) ans.push_back(it.first);
        }
        return ans;
    }
};