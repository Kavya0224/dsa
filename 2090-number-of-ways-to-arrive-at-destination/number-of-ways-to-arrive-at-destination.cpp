class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1'000'000'007;

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : roads) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;  // ✅ prevents TLE

            for (auto [v, w] : adj[u]) {
                long long nd = d + w;

                if (nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                } else if (nd == dist[v]) {
                    ways[v] += ways[u];
                    if (ways[v] >= MOD) ways[v] -= MOD;
                }
            }
        }

        return ways[n-1];
    }
};