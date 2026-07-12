class Solution {
public:
vector<int> par,rank;
    int findPar(int n){
        if(n==par[n]) return n;
        return par[n]=findPar(par[n]);
    }
    void Union(int u,int v){
        int parU=findPar(u);
        int parV=findPar(v);
        if(parU==parV) return;
        if(rank[parU]>rank[parV]) par[parV]=parU;
        else if(rank[parU]<rank[parV]) par[parU]=parV;
        else{
            par[parV]=parU;
            rank[parU]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        par.resize(n);
        rank.resize(n,0);
        iota(par.begin(),par.end(),0);
        for(auto it:pairs) Union(it[0],it[1]);
        vector<vector<char>> temp(n);
        for(int i=0;i<n;i++){
            int par=findPar(i);
            temp[par].push_back(s[i]);
        }
        for(auto &vec : temp) {
             sort(vec.rbegin(), vec.rend());
        }
        for(int i=0;i<n;i++){
            int par=findPar(i);
            s[i]=temp[par].back();
            temp[par].pop_back();
        }
        return s;
    }
};