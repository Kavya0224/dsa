class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=1;i<n;i++){
            string temp="";
            int ct=1;
            for(int i=1;i<s.size();i++){
                if(s[i]==s[i-1]) ct++;
                else{
                    temp+=to_string(ct);
                    temp+=s[i-1];
                    ct=1;
                }
            }
            temp+=to_string(ct);
            temp+=s[s.size()-1];
            s=temp;

        }
        return s;
    }
};