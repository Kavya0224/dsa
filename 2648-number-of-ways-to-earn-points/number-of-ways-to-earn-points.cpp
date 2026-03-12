class Solution {
public:
    vector<vector<int>>dp;
    int mod=1e9+7;
    long long solve(int i,int n,vector<vector<int>>&a,int target){
        if(target==0){       
            return 1;
        }
        if(i==n){
            return target==0;      
        }
        if(dp[i][target]!=-1){    
            return dp[i][target]%mod;       
        }
        long long res=0;            
        for(int j=0;j<=a[i][0];j++){        
            if(target-a[i][1]*j>=0){          
                res+=solve(i+1,n,a,target-a[i][1]*j);
            }
            else
                break;
        }
        return dp[i][target]=res%mod;       
    }
    long long waysToReachTarget(int target, vector<vector<int>>& types) {
        dp.resize(types.size()+1,vector<int>(target+1,-1));
        return solve(0,types.size(),types,target);
    }
};