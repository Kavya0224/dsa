class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        auto getDist = [&](int start) {
            vector<int> dist(n, -1);
            int d = 0, curr = start;
            while (curr != -1 && dist[curr] == -1) {
                dist[curr] = d++;
                curr = edges[curr];
            }
            return dist;
        };

        vector<int> dist1 = getDist(node1);
        vector<int> dist2 = getDist(node2);

        int minMaxDist = 1e9;
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxD = max(dist1[i], dist2[i]);
                if (maxD < minMaxDist) {
                    minMaxDist = maxD;
                    ans = i;
                }
            }
        }

        return ans;
    }
};