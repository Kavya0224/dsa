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
    int Height(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(Height(root->left), Height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int leftHeight = Height(root->left);
        int rightHeight = Height(root->right);

        if (abs(leftHeight - rightHeight) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};