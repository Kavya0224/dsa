class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            unordered_map<char,char> m,mp;
            int f=0;
            for(int j=0;j<pattern.size();j++){
                if(m.find(pattern[j])!=m.end()){
                    if(m[pattern[j]]!=words[i][j]){
                        f=1;
                        break;
                    }
                }
                if(mp.find(words[i][j])!=mp.end()){
                   
                    if(mp[words[i][j]]!=pattern[j]){
                         f=1;
                        break;
                    }
                }
                m[pattern[j]]=words[i][j];
                mp[words[i][j]]=pattern[j];
            }
            if(f==0) ans.push_back(words[i]);
            
            
        }
        return ans;
    }
};