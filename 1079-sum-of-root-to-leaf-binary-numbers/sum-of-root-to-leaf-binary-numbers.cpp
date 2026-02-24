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
    int ans=0;
    void helper(TreeNode* root,int res){
        res=(res<<1)+root->val;
        if(!root->left && !root->right){
            ans+=res;
            return;
        }
        
        if(root->left)helper(root->left,res);
        if(root->right)helper(root->right,res);
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};