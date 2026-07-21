class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ans=0,mx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                int ct=0;
                while(i<s.size() && s[i]=='0'){
                    i++;
                    ct++;
                }
                int f=0;
                while(i<s.size() && s[i]=='1'){
                    f=1;
                    ans++;
                    i++;
                }
                int idx=i;
                if(i<s.size() && s[i]=='0' && f==1){
                    while(i<s.size() && s[i]=='0'){
                        i++;
                        ct++;
                    }
                    mx=max(mx,ct);
                    i=idx-1;
                }
            }
            else ans++;
        }
        return ans+mx;
    }
};