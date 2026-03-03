class Solution {
public:
    string helper(int a, string bin) {
        if (a == 0) return "0";
        while (a > 0) {
            bin.push_back(char('0' + (a % 2))); 
            a /= 2;
        }
        return bin; 
    }
    int minFlips(int a, int b, int c) {

        string s=helper(a,"");
        string t=helper(b,"");
        string ans=helper(c,"");
        int n=s.size();
        int m=t.size();
        int k=ans.size();
        if(n>=m && n>=k){
            while(n!=m){
                t+='0';
                m++;
            }
            while(n!=k){
                ans+='0';
                k++;
            }
        }
        else if(m>=n && m>=k){
            while(n!=m){
                s+='0';
                n++;
            }
            while(m!=k){
                ans+='0';
                k++;
            }
        }
        else{
            while(k!=n){
                s+='0';
                n++;
            }
            while(m!=k){
                t+='0';
                m++;
            }
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(ans[i]=='1' && s[i]=='0' && t[i]=='0') ct++;
            else if(ans[i]=='0' && s[i]=='1' && t[i]=='1') ct+=2;
            else if(ans[i]=='0' && ((s[i]=='0' && t[i]=='1')||(s[i]=='1' && t[i]=='0'))) ct++;
        }
        return ct;
    }
};