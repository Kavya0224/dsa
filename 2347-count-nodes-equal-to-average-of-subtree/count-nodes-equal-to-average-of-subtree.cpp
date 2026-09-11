class Solution {
    int count = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int totalSum = leftSum + rightSum + root->val;
        int totalCount = leftCount + rightCount + 1;

        if (totalSum / totalCount == root->val) {
            count++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        dfs(root);
        return count;
    }
};