class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp;
        for(int i=0;i<grid.size();i++){
            string temp="";
            for(int j=0;j<grid.size();j++){
                temp+=to_string(grid[i][j])+".";
            }
            mp[temp]++;
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            string temp="";
            for(int j=0;j<grid.size();j++){
                temp+=to_string(grid[j][i])+".";
            }
            if(mp.find(temp)!=mp.end()) ans+=mp[temp];
        }
        return ans;
    }
};