class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> str,str1;
        for(int i=0;i<s.length();i++){
            str[s[i]]+=1;
            str1[t[i]]+=1;
        }
        return str==str1;
    }
};