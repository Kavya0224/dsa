class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int temp=min(nums[nums.size()-1]-nums[2],nums[nums.size()-3]-nums[0]);
        int mid=nums.size()/2;
        int temp1=nums[nums.size()-2]-nums[1];
        ans=min(temp1,temp);
        return ans;
    }
};