class Solution {
public:
    bool isSafe(vector<string>& res,int row,int col,int n){
        for(int i=0;i<col;i++){
            if(res[row][i]=='Q') return false;
        }
        for(int i=0;i<row;i++){
            if(res[i][col]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(res[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(res[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(int n,int row,vector<string>& res,vector<vector<string>>& ans){
        if(row==res.size()){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(res,row,i,n)){
                res[row][i]='Q';
                helper(n,row+1,res,ans);
                res[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n,string(n,'.'));
        helper(n,0,res,ans);
        return ans;
    }
};