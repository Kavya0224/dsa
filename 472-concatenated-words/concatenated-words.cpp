class TrieNode {
public:
    bool isEOW;
    TrieNode* child[26];

    TrieNode() {
        isEOW = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* temp = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!temp->child[idx])
                temp->child[idx] = new TrieNode();
            temp = temp->child[idx];
        }
        temp->isEOW = true;
    }

    bool dfs(string &word, int idx, vector<int> &dp) {

        if (idx == word.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        TrieNode* temp = root;
        for (int i = idx; i < word.size(); i++) {
            int c = word[i] - 'a';
            if (!temp->child[c]) break;
            temp = temp->child[c];
            if (temp->isEOW && dfs(word, i + 1, dp))
                return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](const string &a, const string &b) {
                 return a.size() < b.size();
             });

        vector<string> ans;
        for (string &word : words) {
            if (word.empty()) continue;
            vector<int> dp(word.size(), -1);
            if (dfs(word, 0, dp))  ans.push_back(word);

            insert(word);
        }
        return ans;
    }
};