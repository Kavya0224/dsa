class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        unordered_set<string> seen, repeated;

        for (int i = 0; i + 9 < s.size(); i++) {
            string cur = s.substr(i, 10);
            if (seen.count(cur)) repeated.insert(cur);
            else seen.insert(cur);
        }

        return vector<string>(repeated.begin(), repeated.end());
    }
};
