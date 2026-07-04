class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int d=roads[i][2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        queue<int> q;
        q.push(1);
        int mn=INT_MAX;
        vector<bool> vis(n+1,false);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=true;
            for(auto it:adj[u]){
                if(!vis[it.first]){
                    q.push(it.first);
                    mn=min(mn,it.second);
                }
            }
        }
        return mn;
    }
};