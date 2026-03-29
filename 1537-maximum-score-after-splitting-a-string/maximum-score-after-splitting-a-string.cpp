class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> pre(n+1,0),suf(n+1,0);
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0') pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') suf[i]=suf[i+1]+1;
            else suf[i]=suf[i+1];
        }
        int mx=0;
        for(int i=1;i<n;i++) mx=max(mx,pre[i]+suf[i]);
        return mx;
    }
};