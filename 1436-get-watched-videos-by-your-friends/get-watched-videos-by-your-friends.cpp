class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id, int level) {
        int n = friends.size();
        queue<int> q;
        vector<int> dist(n, -1);

        q.push(id);
        dist[id] = 0;

        // BFS to get nodes exactly at distance = level
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nb : friends[cur]) {
                if (dist[nb] == -1) {
                    dist[nb] = dist[cur] + 1;
                    q.push(nb);
                }
            }
        }

        unordered_map<string, int> cnt;

        // Count videos watched by friends at required level
        for (int i = 0; i < n; i++) {
            if (dist[i] == level) {
                for (auto &vid : watchedVideos[i]) {
                    cnt[vid]++;
                }
            }
        }

        vector<pair<string,int>> vec;
        vec.reserve(cnt.size());
        for (auto &p : cnt) vec.push_back({p.first, p.second});

        // sort by frequency then name
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        vector<string> ans;
        ans.reserve(vec.size());
        for (auto &p : vec) ans.push_back(p.first);
        return ans;
    }
};
