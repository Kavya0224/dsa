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
    void helper(TreeNode* root,vector<string>& all,string temp){
        if(!root) return;
        temp+=char(root->val+97);
        if(!root->left && !root->right){
            
            reverse(temp.begin(),temp.end());
            all.push_back(temp);
            return;
        }
       
        helper(root->left,all,temp);
        helper(root->right,all,temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> all;
        helper(root,all,"");
        sort(all.begin(),all.end());
        return all[0];
    }
};