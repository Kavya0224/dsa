class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>> deg(n,{0,0});
        for(auto p:edges){
            deg[p[0]].first++;  //outdeg
            deg[p[1]].second++;  //indeg
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(deg[i].first!=0 && deg[i].second==0) res.push_back(i);
        }
        return res;
    }
};