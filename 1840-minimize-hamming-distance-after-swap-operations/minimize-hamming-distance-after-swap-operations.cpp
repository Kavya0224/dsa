class Solution {
public:
vector<int> par,rank;
    int findPar(int x){
        if(x==par[x]) return x;
        return par[x]=findPar(par[x]);
    }
    void Union(int a,int b){
        int parA=findPar(a);
        int parB=findPar(b);

        if(parA==parB) return;
        if(rank[parA]<rank[parB]) par[parA]=parB;
        else if(rank[parA]>rank[parB]) par[parB]=parA;
        else{
            par[parB]=parA;
            rank[parA]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) par[i]=i;

        for(int i=0;i<allowedSwaps.size();i++){
            Union(allowedSwaps[i][0],allowedSwaps[i][1]);
        }
        unordered_map<int,unordered_map<int,int>> mp;
        for(int i=0;i<n;i++){
            int curr=source[i];
            int p=findPar(i);
            mp[p][curr]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int p=findPar(i);
            
            if(mp[p][target[i]]>0) mp[p][target[i]]--;
            else ans++;
        }
        return ans;
    }
};