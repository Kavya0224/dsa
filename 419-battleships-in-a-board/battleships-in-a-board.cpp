class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j,vector<vector<bool>>& vis){
        
        vis[i][j]=true;
        if(i-1>=0 && board[i-1][j]=='X' && !vis[i-1][j]) dfs(board,i-1,j,vis);
        if(i+1<board.size() && board[i+1][j]=='X' && !vis[i+1][j]) dfs(board,i+1,j,vis);
        if(j-1>=0 && board[i][j-1]=='X' && !vis[i][j-1]) dfs(board,i,j-1,vis);
        if(j+1<board[0].size() && board[i][j+1]=='X'&& !vis[i][j+1]) dfs(board,i,j+1,vis);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    ct++;
                    dfs(board,i,j,vis);
                }
            }
        }
        return ct;
    }
};