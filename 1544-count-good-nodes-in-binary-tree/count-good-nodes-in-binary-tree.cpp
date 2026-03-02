class Solution {
public:
    int ans = 0;

    void helper(TreeNode* root, int maxSoFar) {
        if (!root) return;

        if (root->val >= maxSoFar) ans++;

        maxSoFar = max(maxSoFar, root->val);

        helper(root->left, maxSoFar);
        helper(root->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        helper(root, root->val); // start with root value
        return ans;
    }
};