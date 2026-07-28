class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26);
        int n=s.size();
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        int ch=-1;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1) ch=i;
            freq[i]/=2;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<freq[i];j++) ans+='a'+ i;
        }
        if(ch!=-1) ans+='a'+ch;
        for(int i=25;i>=0;i--){
            for(int j=0;j<freq[i];j++) ans+='a'+ i;
        }
        return ans;
    }
};