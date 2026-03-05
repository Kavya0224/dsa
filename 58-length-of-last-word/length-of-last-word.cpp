class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        while(s[n]==' ') n--;
        int ct=0;
        for(int i=n;i>=0;i--){
            if(s[i]!=' ') ct++;
            else break;
        }
        return ct;
    }
};