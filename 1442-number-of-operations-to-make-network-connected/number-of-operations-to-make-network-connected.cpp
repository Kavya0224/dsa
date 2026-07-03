class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findp(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findp(parent[x]);
    }
    void unionf(int u,int v){
        int pu=findp(u);
        int pv=findp(v);
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    int makeConnected(int n,vector<vector<int>>& connections){
        if(connections.size()<n-1){
            return -1;
        }
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int cnt=0;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(findp(u)!=findp(v)){
                unionf(u,v);
                cnt++;
            }
        }
        return n-cnt-1;
      
    }
};