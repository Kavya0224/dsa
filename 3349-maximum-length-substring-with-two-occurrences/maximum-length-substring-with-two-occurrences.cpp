class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, queue<int>> mp;
        int st = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push(i);
            if (mp[s[i]].size() > 2) {
                st = max(st, mp[s[i]].front() + 1);
                mp[s[i]].pop();
            }
            ans = max(ans, i - st + 1);
        }
        return ans;
    }
};