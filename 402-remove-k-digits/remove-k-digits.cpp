class Solution {
public:
    string removeKdigits(string s, int k) {
        string ans;

        for (char c : s) {
            while (!ans.empty() && k > 0 && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }

        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};