class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        vis[0] = true; 

        while (!q.empty()) {
            auto [idx, dist] = q.front();
            q.pop();

            if (idx == n - 1) return dist;
            if (idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({idx + 1, dist + 1});
            }

            if (idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({idx - 1, dist + 1});
            }

            if (mp.count(arr[idx])) {
                for (int nextIdx : mp[arr[idx]]) {
                    if (!vis[nextIdx]) {
                        vis[nextIdx] = true;
                        q.push({nextIdx, dist + 1});
                    }
                }
                mp.erase(arr[idx]);
            }
        }

        return -1;
    }
};