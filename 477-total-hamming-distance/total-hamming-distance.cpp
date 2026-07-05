class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int x=nums[i]^nums[j];
                int bits=__builtin_popcount(x);
                ans+=bits;
            }
        }
        return ans;
    }
};