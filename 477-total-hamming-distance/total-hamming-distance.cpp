class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans =0;
        int n = nums.size();
        for(int i=0;i<31;i++){
            int ones =0;
            for(int n:nums){
                ones += ((n>>i)&1);
            }
            ans+= (ones*(n-ones));
        }
        return ans;
    }
};