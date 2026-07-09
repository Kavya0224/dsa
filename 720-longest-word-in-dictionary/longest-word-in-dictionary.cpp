class TrieNode{
public:
    bool isEOW;
    string word;
    TrieNode* child[26];

    TrieNode(){
        isEOW = false;
        word = "";
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    string ans = "";

    void insert(TrieNode* root, string &s){
        TrieNode* temp = root;

        for(char c : s){
            if(temp->child[c-'a'] == NULL)
                temp->child[c-'a'] = new TrieNode();

            temp = temp->child[c-'a'];
        }

        temp->isEOW = true;
        temp->word = s;
    }

    void search(TrieNode* root, string &s){

        TrieNode* temp = root;

        for(char c : s){

            if(temp->child[c-'a'] == NULL)
                return;

            temp = temp->child[c-'a'];
            if(!temp->isEOW)
                return;
        }
        if(s.size() > ans.size())
            ans = s;
        else if(s.size() == ans.size())
            ans = min(ans, s);
    }

    string longestWord(vector<string>& words) {

        TrieNode* root = new TrieNode();

        for(string &w : words)
            insert(root, w);

        for(string &w : words)
            search(root, w);

        return ans;
    }
};