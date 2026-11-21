class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        
        vector<vector<int>> original_adj(n);
        for (int i = 1; i < n; ++i) {
            original_adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);
        auto findNewParents = [&](auto& self, int u) -> void {
            char ch = s[u];
            int prev_ancestor = last_seen[ch - 'a'];
            
            if (prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }
            
            last_seen[ch - 'a'] = u;

            for (int v : original_adj[u]) {
                self(self, v);
            }

            last_seen[ch - 'a'] = prev_ancestor;
        };

        findNewParents(findNewParents, 0);

        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        auto calculateSubtreeSizes = [&](auto& self, int u) -> int {
            int current_size = 1;
            for (int v : new_adj[u]) {
                current_size += self(self, v);
            }
            ans[u] = current_size;
            return current_size;
        };

        calculateSubtreeSizes(calculateSubtreeSizes, 0);

        return ans;
    }
};