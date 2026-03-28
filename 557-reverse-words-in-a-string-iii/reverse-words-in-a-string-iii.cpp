class Solution {
public:
    string reverseWords(string s) {
        string temp="",ans="";
        int i=0;
        while(i<s.size()){
            if(s[i]==' '){
                reverse(temp.begin(),temp.end());
                ans+=temp+" ";
                temp="";
            }
            else temp+=s[i];
            i++;
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};