class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int a=costs[i-1]+1+dp[i-1];
            int b=INT_MAX,c=INT_MAX;
            if(i>=2) b=costs[i-1]+4+dp[i-2];
            if(i>=3) c=costs[i-1]+9+dp[i-3];
            dp[i]=min({a,b,c});
        }
        return dp[n];
    }
};