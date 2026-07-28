class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second; 
            }
            return a.first > b.first; 
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);

        for (const auto& entry : freq) {
            pq.push({entry.second, entry.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().second;
            pq.pop();
        }

        return result;
    }
};