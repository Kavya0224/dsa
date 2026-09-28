class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) ct++;
        }
        int ans=0;
        for(int i=nums.size()-ct;i<nums.size();i++){
            if(nums[i]!=0) ans++;
        }
        return ans;
    }
};