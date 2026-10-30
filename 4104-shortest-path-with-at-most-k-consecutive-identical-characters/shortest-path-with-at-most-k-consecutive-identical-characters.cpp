class Solution {
public:
    long long shortestPath(int n,vector<vector<int>>& edges,string labels,int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(
            n,
            vector<long long>(k + 1, INF)
        );

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1}); // cost,node,streak

        while (!pq.empty()) {

            auto [d, u, streak] = pq.top();
            pq.pop();

            if (d != dist[u][streak])
                continue;

            if (u == n - 1)
                return d;

            for (auto &[v, w] : adj[u]) {

                int ns;

                if (labels[u] == labels[v]) {
                    ns = streak + 1;
                    if (ns > k) continue;
                } else {
                    ns = 1;
                }

                long long nd = d + w;

                if (nd < dist[v][ns]) {
                    dist[v][ns] = nd;
                    pq.push({nd, v, ns});
                }
            }
        }

        return -1;
    }
};