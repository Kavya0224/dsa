class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0,j=0;
        long long pro=1,count=0;
        while(j<nums.size())
        {
            pro*=nums[j];
            while(pro>=k){
                pro/=nums[i]; i++;
            }
            if(pro<k) count+=(j-i+1);
            j++;
        }
        return count;
    }
};