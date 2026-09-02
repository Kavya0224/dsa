class Solution {
    int getDepth(int u, vector<int>& parent, vector<int>& depth) {
        if (depth[u] != 0) return depth[u];
        return depth[u] = 1 + getDepth(parent[u], parent, depth);
    }
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<int> depth(n, 0);
        depth[0] = 1;
        
        int max_h = 1;
        for (int i = 0; i < n; ++i) {
            max_h = max(max_h, getDepth(i, parent, depth));
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * nums[i] * (max_h - depth[i] + 1);
        }
        return ans;
    }
};