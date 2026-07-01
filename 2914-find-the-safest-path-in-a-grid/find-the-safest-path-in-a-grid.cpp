class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i+1<n && grid[i+1][j]==0 && !vis[i+1][j]){
                q.push({i+1,j});
                grid[i+1][j]=grid[i][j]+1;
                vis[i+1][j]=true;
            }
            if(i-1>=0 && grid[i-1][j]==0 && !vis[i-1][j]){
                q.push({i-1,j});
                grid[i-1][j]=grid[i][j]+1;
                vis[i-1][j]=true;
            }
            if(j+1<m && grid[i][j+1]==0 && !vis[i][j+1]){
                q.push({i,j+1});
                grid[i][j+1]=grid[i][j]+1;
                vis[i][j+1]=true;
            }
            if(j-1>=0 && grid[i][j-1]==0 && !vis[i][j-1]){
                q.push({i,j-1});
                grid[i][j-1]=grid[i][j]+1;
                vis[i][j-1]=true;
            }
        }
        vis.assign(n, vector<bool>(m, false));
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        int ans=INT_MAX;
        while(!pq.empty()){
            int val=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            ans=min(ans,val);
            if(ans==1) return 0;
            if(i==n-1 && j==m-1) return ans-1;
            if(i+1<n && !vis[i+1][j]){
                pq.push({grid[i+1][j],{i+1,j}});
                vis[i+1][j]=true;
            }
            if(i-1>=0 && !vis[i-1][j]){
                pq.push({grid[i-1][j],{i-1,j}});
                vis[i-1][j]=true;
            }
            if(j+1<m && !vis[i][j+1]){
                pq.push({grid[i][j+1],{i,j+1}});
                vis[i][j+1]=true;
            }
            if(j-1>=0 && !vis[i][j-1]){
                pq.push({grid[i][j-1],{i,j-1}});
                vis[i][j-1]=true;
            }
        }
        return 0;
    }
};