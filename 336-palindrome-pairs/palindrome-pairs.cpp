class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        int wordIndex = -1;
        vector<int> arr;
    };

    bool isPalindrome(const string& word, int i, int j) {
        while (i < j) {
            if (word[i++] != word[j--]) return false;
        }
        return true;
    }

    void insert(TrieNode* root, const string& word, int wordIdx) {
        TrieNode* curr = root;
        for (int i = word.length() - 1; i >= 0; --i) {
            if (isPalindrome(word, 0, i)) {
                curr->arr.push_back(wordIdx);
            }
            
            int charIdx = word[i] - 'a';
            if (!curr->children[charIdx]) {
                curr->children[charIdx] = new TrieNode();
            }
            curr = curr->children[charIdx];
        }
        curr->wordIndex = wordIdx;
        curr->arr.push_back(wordIdx);
    }

    void search(const string& word, int wordIdx, TrieNode* root, vector<vector<int>>& result) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); ++i) {
            if (curr->wordIndex != -1 && curr->wordIndex != wordIdx && isPalindrome(word, i, word.length() - 1)) {
                result.push_back({wordIdx, curr->wordIndex});
            }

            int charIdx = word[i] - 'a';
            if (!curr->children[charIdx]) return;
            curr = curr->children[charIdx];
        }

        for (int palIdx : curr->arr) {
            if (palIdx == wordIdx) continue;
            result.push_back({wordIdx, palIdx});
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<vector<int>> result;

        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i], i);
        }

        for (int i = 0; i < words.size(); ++i) {
            search(words[i], i, root, result);
        }

        return result;
    }
};