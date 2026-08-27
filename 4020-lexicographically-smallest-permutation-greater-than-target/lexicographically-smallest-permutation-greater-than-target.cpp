class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> total_freq(26, 0);
        for (char c : s) {
            total_freq[c - 'a']++;
        }
        for (int len = n - 1; len >= 0; len--) {
            vector<int> freq = total_freq;
            bool possible = true;
            for (int i = 0; i < len; i++) {
                if (--freq[target[i] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            int next_char = -1;
            for (int c = target[len] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    next_char = c;
                    break;
                }
            }
            if (next_char != -1) {
                string ans = target.substr(0, len);
                ans += (char)('a' + next_char);
                freq[next_char]--;

                for (int c = 0; c < 26; c++) {
                    while (freq[c] > 0) {
                        ans += (char)('a' + c);
                        freq[c]--;
                    }
                }
                return ans;
            }
        }

        return "";
    }
};