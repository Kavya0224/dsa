class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ct=0;
        vector<vector<pair<int,int>>> mat(n,vector<pair<int,int>>(m));
        if(grid[0][0]=='X') mat[0][0]={1,0};
        else if(grid[0][0]=='Y') mat[0][0]={0,1};
        else mat[0][0]={0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                else if(i==0){
                if(grid[i][j]=='X')  mat[i][j]={mat[i][j-1].first+1,mat[i][j-1].second};
                else if(grid[i][j]=='Y') mat[i][j]={mat[i][j-1].first,mat[i][j-1].second+1};
                else mat[i][j]=mat[i][j-1];
                }
                else if(j==0){
                    if(grid[i][j]=='X')  mat[i][j]={mat[i-1][j].first+1,mat[i-1][j].second};
                else if(grid[i][j]=='Y') mat[i][j]={mat[i-1][j].first,mat[i-1][j].second+1};
                else mat[i][j]=mat[i-1][j];
                }
                else{
                    if(grid[i][j]=='X')  mat[i][j]={mat[i-1][j].first+mat[i][j-1].first-mat[i-1][j-1].first+1,mat[i-1][j].second+mat[i][j-1].second-mat[i-1][j-1].second};
                else if(grid[i][j]=='Y')  mat[i][j]={mat[i-1][j].first+mat[i][j-1].first-mat[i-1][j-1].first,mat[i-1][j].second+mat[i][j-1].second-mat[i-1][j-1].second+1};
                else  mat[i][j]={mat[i-1][j].first+mat[i][j-1].first-mat[i-1][j-1].first,mat[i-1][j].second+mat[i][j-1].second-mat[i-1][j-1].second};
                }
                if(mat[i][j].first==mat[i][j].second && mat[i][j].first) ct++;
            }
            

        }
        return ct;
    }
};