class Solution {
public:
    vector<vector<int>> adj;
    vector<int> count, ans;
    int n;

    void dfs1(int node, int parent, int depth) {
        ans[0] += depth;     // sum of distances from root 0
        count[node] = 1;     // include itself

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            dfs1(nei, node, depth + 1);
            count[node] += count[nei];
        }
    }

    void dfs2(int node, int parent) {
        for (int nei : adj[node]) {
            if (nei == parent) continue;

            // reroot from node -> nei
            ans[nei] = ans[node] - count[nei] + (n - count[nei]);

            dfs2(nei, node);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        adj.assign(n, {});
        count.assign(n, 0);
        ans.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, 0);
        dfs2(0, -1);

        return ans;
    }
};