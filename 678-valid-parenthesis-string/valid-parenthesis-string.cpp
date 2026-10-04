class Solution {
public:
    bool checkValidString(string s) {
        int ct=0,extra=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') ct++;
            else if(s[i]=='*') extra++;
            else ct--;
            if(ct<0){
                if(extra<=0) return false;
                else{
                    extra--;
                    ct++;
                }
            }

        }
        ct=0,extra=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') ct--;
            else if(s[i]=='*') extra++;
            else ct++;
            if(ct<0){
                if(extra<=0) return false;
                else{
                    extra--;
                    ct++;
                }
            }
        }
        return true;
    }
};