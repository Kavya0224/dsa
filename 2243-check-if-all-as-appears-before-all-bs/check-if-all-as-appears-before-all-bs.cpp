class Solution {
public:
    bool checkString(string s) {
        int f=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b') f=1;
            else if(f==1 && s[i]=='a') return false;
        }
        return true;
    }
};