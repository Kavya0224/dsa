class TrieNode{
public:
    bool isEOW;
    string word;
    TrieNode* child[26];
    TrieNode(){
        isEOW = false;
        word = "";
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
};
class Solution {
public:
    void insert(TrieNode* root,string& s){
        TrieNode* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->child[s[i]-'a']==NULL){
                temp->child[s[i]-'a']=new TrieNode();
            }
            temp=temp->child[s[i]-'a'];
        }
        temp->isEOW=true;
        temp->word=s;
    }
    string search(TrieNode* root,string s){
        TrieNode* temp=root;
        for(int i=0;i<s.size();i++){
            if(temp->child[s[i]-'a']!=NULL){
                temp=temp->child[s[i]-'a'];
                if(temp->isEOW){
                    return temp->word;
                }
            }
            else return s;
        }
        return s;
    }
    string replaceWords(vector<string>& dict, string sent) {
        TrieNode* root=new TrieNode();
        string ans="";
        for(int i=0;i<dict.size();i++) insert(root,dict[i]);
        for(int i=0;i<sent.size();i++){
            string t="";
            while(i<sent.size() && sent[i]!=' '){
                t+=sent[i];
                i++;
            }
            string rep=search(root,t);
            ans+=" "+rep;
        }
        return ans.substr(1);
    }
};