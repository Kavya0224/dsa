class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=min(n,8);
        n-=ans;
        ans+=2*min(8,n);
        n-=(min(n,8));
        ans+=3*min(n,8);
        n-=(min(n,8));
        ans+=4*min(n,2);
        return ans;
    }
};