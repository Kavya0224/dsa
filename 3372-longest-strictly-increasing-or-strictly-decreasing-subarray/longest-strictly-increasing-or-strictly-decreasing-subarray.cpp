class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx=1,mn=1;
        int curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) curr++;
            else curr=1;
            mx=max(mx,curr);
        }
        curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) curr++;
            else curr=1;
            mn=max(mn,curr);
        }
        return max(mx,mn);
    }
};