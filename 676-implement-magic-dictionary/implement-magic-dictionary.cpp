class MagicDictionary {
    struct TrieNode {
        TrieNode* child[26] = {nullptr};
        bool isEOW = false;
    };

    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int index, int count) {
        if (count > 1) return false; 
        if (index == word.size()) {
            return node->isEOW && count == 1; 
        }

        int charIdx = word[index] - 'a';

        for (int j = 0; j < 26; j++) {
            if (!node->child[j]) continue;

            int newCount = count + (j != charIdx ? 1 : 0);
            if (dfs(node->child[j], word, index + 1, newCount)) {
                return true;
            }
        }

        return false;
    }

public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for (const string& word : dictionary) {
            TrieNode* temp = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!temp->child[idx]) {
                    temp->child[idx] = new TrieNode();
                }
                temp = temp->child[idx];
            }
            temp->isEOW = true;
        }
    }
    
    bool search(string searchWord) {
        return dfs(root, searchWord, 0, 0);
    }
};