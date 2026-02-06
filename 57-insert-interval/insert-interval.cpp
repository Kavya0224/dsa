class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        
         nums.push_back({newInterval[0],newInterval[1]});
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=1;i<=nums.size();i++){
            int st=nums[i-1][0];
            int mx=nums[i-1][1];
            while(i<nums.size() && mx>=nums[i][0]){
                i++;
                mx=max(nums[i-1][1],mx);
            }
            ans.push_back({st,mx});
        }
        return ans;
    }
};