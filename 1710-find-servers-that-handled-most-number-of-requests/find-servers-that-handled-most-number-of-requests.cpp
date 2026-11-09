class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        set<int> free_servers;
        for (int i = 0; i < k; ++i) free_servers.insert(i);

        vector<int> request_count(k, 0);
        int max_requests = 0;

        for (int i = 0; i < arrival.size(); ++i) {
            int curr_time = arrival[i];

            while (!busy.empty() && busy.top().first <= curr_time) {
                free_servers.insert(busy.top().second);
                busy.pop();
            }

            if (free_servers.empty()) continue;

            auto it = free_servers.lower_bound(i % k);
            if (it == free_servers.end()) {
                it = free_servers.begin();
            }

            int server_id = *it;
            free_servers.erase(it);

            busy.push({curr_time + load[i], server_id});
            request_count[server_id]++;
            max_requests = max(max_requests, request_count[server_id]);
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (request_count[i] == max_requests) {
                result.push_back(i);
            }
        }
        return result;
    }
};