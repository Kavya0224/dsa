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
    void helper(TreeNode* root,vector<int>& a){
        if(!root->left && !root->right) a.push_back(root->val);
        if(root->left) helper(root->left,a);
        if(root->right) helper(root->right,a);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr;
        vector<int> brr;
        helper(root1,arr);
        helper(root2,brr);
        if(arr.size()!=brr.size()) return false;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=brr[i]) return false;
        }
        return true;
    }
};