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
    void helper(TreeNode* root,int mx,int mn){
       if(abs(mx-mn)>ans) ans=abs(mx-mn);
        if(!root) return;
        
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        helper(root->left,mx,mn);
        helper(root->right,mx,mn);

    }
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
};