class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i=0;i<invocations.size();i++) adj[invocations[i][0]].push_back(invocations[i][1]);
        vector<int> vis(n,false);
        queue<int> q;
        q.push(k);
        vis[k]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vector<int> temp;
        int f=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                temp.push_back(i);
                for(int u:adj[i]){
                    if(vis[u]){
                        f=1;
                        break;
                    }
                }
            }
            if(f==1) break;
        }
        vector<int> ans(n);
        if(f==1){
            iota(ans.begin(),ans.end(),0);
            return ans;
        }
        return temp;
    }
};