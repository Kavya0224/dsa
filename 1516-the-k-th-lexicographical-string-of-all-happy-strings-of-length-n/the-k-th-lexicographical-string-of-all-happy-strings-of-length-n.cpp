class Solution {
public:
    void helper(int n,vector<char> s,vector<char> ans,vector<vector<char>>& res){
        if(n==ans.size()){
            res.push_back({ans});
            return;
        }
        for(int i=0;i<3;i++){
            if(ans.size()!=0){
                if(ans[ans.size()-1]==s[i]) continue;
            }
            ans.push_back(s[i]);
            
            helper(n,s,ans,res);
            ans.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<char> s={'a','b','c'};
        vector<char> ans;
        vector<vector<char>> res;
        helper(n,s,ans,res);
        string st="";
        for(int i=0;i<res.size();i++){
            if(i==k-1){
                for(int j=0;j<res[i].size();j++){
                    st+=res[i][j];
                }
                
            }
            if(st.size()!=0) break;
        }
        return st;
    }
};