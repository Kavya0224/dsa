class Solution {
public:
    int minimumCost(vector<int>& nums) 
    {
        int temp=nums[0];
        sort(nums.begin(),nums.end());
        if(temp!=nums[0] && temp!=nums[1]&&temp!=nums[2]){
            return temp+nums[0]+nums[1];
        }
        return nums[0]+nums[1]+nums[2];
    }
};