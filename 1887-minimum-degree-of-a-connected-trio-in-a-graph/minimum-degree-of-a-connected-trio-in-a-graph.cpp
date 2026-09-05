class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
    // al[u] stores all neighbors v such that u < v
    vector<vector<int>> al(n + 1);
    vector<vector<bool>> connected(n + 1, vector<bool>(n + 1, false));
    vector<int> degree(n + 1, 0);

    for (const auto& edge : edges) {
        int u = min(edge[0], edge[1]);
        int v = max(edge[0], edge[1]);
        al[u].push_back(v);
        connected[u][v] = true;
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    int res = INT_MAX;

    // Pick node u, then pick any two neighbors v and w of u
    for (int u = 1; u <= n; ++u) {
        int neighbors = al[u].size();
        for (int i = 0; i < neighbors; ++i) {
            int v = al[u][i];
            for (int j = i + 1; j < neighbors; ++j) {
                int w = al[u][j];

                // If v and w are connected, we found a trio (u, v, w)
                if (connected[min(v, w)][max(v, w)]) {
                    int trioDegree = degree[u] + degree[v] + degree[w] - 6;
                    res = min(res, trioDegree);
                }
            }
        }
    }

    return res == INT_MAX ? -1 : res;
}
};