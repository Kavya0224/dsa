class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        unsigned long long n=grid.size();
        unsigned long long m=grid[0].size();
        vector<vector<unsigned long long>> hor(n,vector<unsigned long long>(m)),ver(n,vector<unsigned long long>(m));
        vector<unsigned long long> hori(n+1,0),veri(m+1,0);
        for(unsigned long long i=0;i<n;i++){
            hor[i][0]=grid[i][0];
            for(unsigned long long j=1;j<m;j++){
                hor[i][j]=hor[i][j-1]+grid[i][j];
            }
            hori[i+1]=hori[i]+hor[i][m-1];
        }
        for(unsigned long long i=0;i<m;i++){
            ver[0][i]=grid[0][i];
            for(unsigned long long j=1;j<n;j++){
                ver[j][i]=ver[j-1][i]+grid[j][i];
            }
            veri[i+1]=veri[i]+ver[n-1][i];
        }
        for(unsigned long long i=2;i<=n;i++){
            if(hori[i-1]==hori[n]-hori[i-1]) return true;
        }
        for(unsigned long long i=2;i<=m;i++){
            if(veri[i-1]==veri[m]-veri[i-1]) return true;
        }
        return false;
    }
};