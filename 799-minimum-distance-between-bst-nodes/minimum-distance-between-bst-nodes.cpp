class Solution {
public:
    int diff = INT_MAX;
    TreeNode* prev = nullptr;
    void helper(TreeNode* root) {
        if (!root) return;
        helper(root->left);

        if (prev != nullptr) {
            diff = min(diff, root->val - prev->val);
        }
        prev = root;
        helper(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        helper(root);
        return diff;
    }
};