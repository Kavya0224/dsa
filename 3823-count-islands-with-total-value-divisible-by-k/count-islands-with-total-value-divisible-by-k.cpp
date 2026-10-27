class Solution {
public:
    long long dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int u,int v){
        long long sum=0;
        queue<pair<int,int>> q;
        q.push({u,v});
        vis[u][v]=true;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            sum+=grid[i][j];
            if(i+1<grid.size() && vis[i+1][j]==false && grid[i+1][j]!=0){
                q.push({i+1,j});
                vis[i+1][j]=true;
            }
            if(j+1<grid[0].size() && vis[i][j+1]==false && grid[i][j+1]!=0){
                q.push({i,j+1});
                vis[i][j+1]=true;
            }
            if(i-1>=0 && vis[i-1][j]==false && grid[i-1][j]!=0){
                q.push({i-1,j});
                vis[i-1][j]=true;
            }
            if(j-1>=0 && vis[i][j-1]==false && grid[i][j-1]!=0){
                q.push({i,j-1});
                vis[i][j-1]=true;
            }

        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || grid[i][j]==0) continue;
                long long temp=dfs(grid,vis,i,j);
                if(temp%k==0) ct++;
            }
        }
        return ct;
    }
};