class TrieNode{
public:
    bool isEOW;
    TrieNode* child[26];
    TrieNode(){
        isEOW=false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

class Solution {
public:
 int helper(TrieNode* node, int depth) {
        bool isLeaf = true;
        int totalLength = 0;

        for (int i = 0; i < 26; i++) {
            if (node->child[i]) {
                isLeaf = false;
                totalLength += helper(node->child[i], depth + 1);
            }
        }
        if (isLeaf) {
            return depth + 1;
        }

        return totalLength;
    }
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(int i=0;i<words.size();i++){
            int n=words[i].size()-1;
            TrieNode* temp=root;
            for(int j=n;j>=0;j--){
                if(temp->child[words[i][j]-'a']==NULL){
                    temp->child[words[i][j]-'a']=new TrieNode();
                }
               temp=temp->child[words[i][j]-'a'];
            }
            temp->isEOW=true;
        }
        
        return helper(root,0);
     
    }
};