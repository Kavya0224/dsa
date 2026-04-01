class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";
        int mx = 0;
        string ans = "";

        for (int i = 0; i <= paragraph.size(); i++) {
            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            } 
            else {
                if (!word.empty() && ban.find(word) == ban.end()) {
                    freq[word]++;
                    if (freq[word] > mx) {
                        mx = freq[word];
                        ans = word;
                    }
                }
                word = "";
            }
        }

        return ans;
    }
};