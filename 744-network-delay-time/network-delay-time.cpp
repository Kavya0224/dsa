class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto it:adj[u]){
                int v=it.first;
                int time=it.second;
                if(wt+time<dist[v]){
                    dist[v]=wt+time;
                    pq.push({wt+time,v});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,dist[i]);
        }
        return mx==INT_MAX?-1:mx;
    }
};