class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0;
        int ct=0;
        unordered_set<string> st;
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a') a++;
            if(s[i]=='b') b++;
            if(s[i]=='c') c++;
            while(a && b && c){
                ct+=n-i;
                if(s[l]=='a') a--;
                if(s[l]=='b') b--;
                if(s[l]=='c') c--;
                l++;
            }
        }
        return ct;
    }
};