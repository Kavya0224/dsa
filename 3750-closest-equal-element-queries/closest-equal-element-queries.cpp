class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> dist(n, -1);

        for (auto &it : mp) {
            auto &v = it.second;
            int sz = v.size();
            
            if (sz == 1) continue;

            for (int i = 0; i < sz; i++) {
                int prev = v[(i - 1 + sz) % sz];
                int next = v[(i + 1) % sz];

                int d1 = abs(v[i] - prev);
                int d2 = abs(v[i] - next);
                d1 = min(d1, n - d1);
                d2 = min(d2, n - d2);

                dist[v[i]] = min(d1, d2);
            }
        }

        vector<int> ans;
        for (int q : queries) {
            ans.push_back(dist[q]);
        }

        return ans;
    }
};