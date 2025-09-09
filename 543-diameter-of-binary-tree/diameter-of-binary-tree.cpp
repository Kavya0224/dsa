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
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;        
    }

private:
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);

        res = max(res, l + r);

        return 1 + max(l, r);
    }    
};

// class Solution {
// public:
// int Height(TreeNode* root){
//     if(root==NULL){
//         return 1;
//     }
//     return max(Height(root->left),Height(root->right))+1;
// }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int lf=Height(root->left);
//         int rht=Height(root->right);
//         return rht+lf-2;
        
//     }
// };