class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        // Push all land cells
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // Edge case: all land or all water
        if(q.empty() || q.size() == n * m) return -1;
        
        int ans = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            
            for(int d = 0; d < 4; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                
                if(ni >= 0 && nj >= 0 && ni < n && nj < m && dist[ni][nj] == -1){
                    dist[ni][nj] = dist[i][j] + 1;
                    ans = max(ans, dist[ni][nj]);
                    q.push({ni, nj});
                }
            }
        }
        
        return ans;
    }
};
