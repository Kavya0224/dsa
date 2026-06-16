class Solution {
public:
    string processStr(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') res+=s[i];
            else if(s[i]=='*' && res.size()>0) res.erase(res.size()-1,1);
            else if(s[i]=='#' && res.size()>0) res+=res;
            else reverse(res.begin(),res.end());
        }
        return res;
    }
};