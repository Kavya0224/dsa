class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=true;
                int par=adj[i].size();
                int ct=0;
                while(!q.empty()){
                    int u=q.front();
                    int temp=adj[u].size();
                    par=min(par,temp);
                    ct++;
                    q.pop();
                    for(auto it:adj[u]){
                        if(!vis[it]){
                            vis[it]=true;
                            q.push(it);
                        }
                    }
                }
                if(ct-1==par) ans++;
            }
        }
        return ans;
    }
};