class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i]={adj[i].size(),i};
        }
        sort(arr.begin(),arr.end());
        unsigned long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*(arr[i].first)*(i+1);
        }
        return ans;
    }
};