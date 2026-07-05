class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        dp[0][0]={0,1};
        const int MOD = 1e9 + 7;
        for(int i=1;i<n;i++){
            if(board[0][i]=='X'){
                    break;
            }
            dp[0][i].first=dp[0][i-1].first+board[0][i]-'0';
            dp[0][i].second=1;
        }
        for(int i=1;i<n;i++){
            if(board[i][0]=='X'){
                    break;
            }
            dp[i][0].first=dp[i-1][0].first+board[i][0]-'0';
            dp[i][0].second=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(board[i][j]=='X'){
                    continue;
                }

                int a=dp[i-1][j-1].first;
                int b=dp[i-1][j].first;
                int c=dp[i][j-1].first;
                
                int mx=max({a,b,c});
                if(mx && board[i][j]!='S') dp[i][j].first=mx+board[i][j]-'0';
                else dp[i][j].first=mx;
                if(mx==a) dp[i][j].second+=dp[i-1][j-1].second;
                if(mx==b) dp[i][j].second+=dp[i-1][j].second;
                if(mx==c) dp[i][j].second+=dp[i][j-1].second;
                dp[i][j].second = dp[i][j].second % MOD;
            }
        }
        return {dp[n-1][n-1].first,dp[n-1][n-1].second};
    }
};