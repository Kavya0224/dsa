class Solution {
public:
vector<int> par;
vector<int> rank;
    int find(int n){
        if(n==par[n]) return n;
        return par[n]=find(par[n]);
    }
    void Union(int u,int v){
        int parU=find(u);
        int parV=find(v);
       
        if(rank[parU]>rank[parV]){
            par[parV]=parU;
        }
        else if(rank[parU]<rank[parV]){
            par[parU]=parV;
        }
        else{
            rank[parU]++;
            par[parV]=parU;
        }
        
    }
    int numSimilarGroups(vector<string>& strs) {
        par.resize(strs.size());
        for(int i=0;i<strs.size();i++) par[i]=i;
        rank.resize(strs.size(),0);
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                int diff=0;
                if(strs[i].size()!=strs[j].size()) continue;
                for(int k=0;k<strs[i].size();k++){
                    if(strs[i][k]!=strs[j][k]) diff++;
                    if(diff>2) break;
                }
                if(diff<=2) Union(i,j);
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<strs.size();i++){
            int u=find(i);
            mp[u]++;
        }
        return mp.size();
    }
};