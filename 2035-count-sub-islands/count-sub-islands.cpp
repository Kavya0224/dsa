class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int ct=0;
        for(int u=0;u<n;u++){
            for(int v=0;v<m;v++){
                if(!vis[u][v] && grid2[u][v]==1){
                    q.push({u,v});
                    vis[u][v]=true;
                    int f=0;
                    while(!q.empty()){
                        int i=q.front().first;
                        int j=q.front().second;
                        q.pop();
                        if(grid1[i][j]!=1) f=1;
                        
                        if(i-1>=0 && !vis[i-1][j] && grid2[i-1][j]==1){
                            q.push({i-1,j});
                            vis[i-1][j]=true;
                        }
                        if(i+1<n && !vis[i+1][j] && grid2[i+1][j]==1){
                            q.push({i+1,j});
                            vis[i+1][j]=true;
                        }
                        if(j+1<m && !vis[i][j+1] && grid2[i][j+1]==1){
                            q.push({i,j+1});
                            vis[i][j+1]=true;
                        }
                        if(j-1>=0 && !vis[i][j-1] && grid2[i][j-1]==1){
                            q.push({i,j-1});
                            vis[i][j-1]=true;
                        }
                    }
                    if(f==0) ct++;
                }
            }
        }
        return ct;
    }
};