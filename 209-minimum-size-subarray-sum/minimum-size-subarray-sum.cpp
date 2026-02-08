class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int mn=INT_MAX;
        int sum=0;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            
            while(l<nums.size() && sum>=target){
                 mn=min(mn,r-l+1);
                sum-=nums[l];
                l++;
               
            }
           
        }
        if(mn==INT_MAX) return 0;
        return mn;
    }
};