class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=true;
            if(u==destination) return true;
            for(int v:adj[u]){
                if(!vis[v]){
                    q.push(v);
                }
            }
        }
        return false;
    }
};