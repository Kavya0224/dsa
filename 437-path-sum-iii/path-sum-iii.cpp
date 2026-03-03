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
    unordered_map<long long, int> mp;
    int ans = 0;

    void solve(TreeNode* root, int tar, long long sum) {
        if (!root) return;

        sum += root->val;
        if (mp.find(sum - tar) != mp.end()) {
            ans += mp[sum - tar];
        }

        mp[sum]++;
        solve(root->left, tar, sum);
        solve(root->right, tar, sum);
        
        // Backtrack: remove current sum so it doesn't affect other branches
        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        solve(root, targetSum, 0);
        return ans;
    }
};