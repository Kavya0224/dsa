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
    vector<int> arr;
    void helper(TreeNode* root){
        if(!root) return;
        arr.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        helper(root);
        sort(arr.begin(),arr.end());
        TreeNode* node=new TreeNode(arr[0]);
        root=node;
        int i=1;
        while(i<arr.size()){
            node->right=new TreeNode(arr[i]);
            node=node->right;
            i++;
        }
        return root;
    }
};