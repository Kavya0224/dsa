class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s.empty() || words.empty()) return ans;

        int n = s.size();
        int wc = words.size();
        int wl = words[0].size();
        int totalLen = wc * wl;

        if (n < totalLen) return ans;

        unordered_map<string, int> need;
        for (auto &w : words) need[w]++;

        for (int offset = 0; offset < wl; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> have;

            for (int right = offset; right + wl <= n; right += wl) {
                string word = s.substr(right, wl);

                if (need.find(word) != need.end()) {
                    have[word]++;
                    count++;

                    while (have[word] > need[word]) {
                        string leftWord = s.substr(left, wl);
                        have[leftWord]--;
                        left += wl;
                        count--;
                    }

                    if (count == wc) {
                        ans.push_back(left);

                        string leftWord = s.substr(left, wl);
                        have[leftWord]--;
                        left += wl;
                        count--;
                    }
                } else {
                    have.clear();
                    count = 0;
                    left = right + wl;
                }
            }
        }

        return ans;
    }
};