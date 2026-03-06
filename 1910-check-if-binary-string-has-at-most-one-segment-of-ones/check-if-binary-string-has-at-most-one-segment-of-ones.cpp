class Solution {
public:
    bool checkOnesSegment(string s) {
        int f=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1' && f==0){
                while(s[i]=='1') i++;
                f=1;
                i--;
            }
            else if(s[i]=='1' && f==1) return false;
        }
        return true;
    }
};