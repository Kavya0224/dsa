class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<int> ans;
        for(int i=0;i<nums.size();i++) vis[nums[i]-1]=true;
        for(int i=0;i<nums.size();i++){
            if(!vis[i]) ans.push_back(i+1);
        }
        return ans;
    }
};