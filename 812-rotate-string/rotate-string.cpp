class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s==goal){
                return true;
            }
            temp=s[0];
            s.erase(0,1);
            s+=temp;
        }
        return false;
    }
};