class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> deg(n,0);

        for(auto &r : roads){
            adj[r[0]].push_back(r[1]);
            adj[r[1]].push_back(r[0]);
            deg[r[0]]++;
            deg[r[1]]++;
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cur = deg[i] + deg[j];

                // check if directly connected
                for(int v : adj[i]){
                    if(v == j){
                        cur--;
                        break;
                    }
                }

                ans = max(ans, cur);
            }
        }
        return ans;
    }
};
