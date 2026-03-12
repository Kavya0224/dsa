class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int mx=INT_MIN;
        vector<int> dp(n+k+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=energy[i]+dp[i+k];
            mx=max(mx,dp[i]);
        }
        return mx;
    }
    //     int ans=INT_MIN;
    //     int n=energy.size();
    //     for(int i=0;i<n;i++){
    //         int e=energy[i];
    //         for(int j=i+k;j<n;j=j+k){
    //             e+=energy[j];
    //         }
    //         ans=max(ans,e);
    //     }
    //     return ans;
    // }
};