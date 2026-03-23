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
    bool helper(TreeNode* root,int tar){
        if(!root) return true;
        if(root->val!=tar) return false;
        return helper(root->left,tar) && helper(root->right,tar);
    }
    bool isUnivalTree(TreeNode* root) {
        return helper(root,root->val);
    }
};