class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> dist(edges.size(),0);
        long long ans=0,mx=0;
        for(long long i=0;i<edges.size();i++){
            if(edges[i]!=-1) dist[edges[i]]+=1LL*i;
        }
        for(long long i=0;i<edges.size();i++){
            if(dist[i]>mx){
                mx=dist[i];
                ans=i;
            }
        }
        return ans;
    }
};