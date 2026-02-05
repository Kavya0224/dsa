class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int idx;
            if(nums[i]>0){
                idx=(i+nums[i])%n;
            }
            else if(nums[i]<0){
                idx = ((i + nums[i]) % n + n) % n;
            }
            else idx=i;
            res[i]=nums[idx];
        }
        return res;
    }
};