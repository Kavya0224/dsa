class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++) mp[knowledge[i][0]]=knowledge[i][1];
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                if(mp.find(temp)!=mp.end()) ans+=mp[temp];
                else ans+='?';
            }
            else ans+=s[i];
        }
        return ans;
    }
};