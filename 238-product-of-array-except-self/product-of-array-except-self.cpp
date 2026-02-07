class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int f=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                f++;
                continue;
            }
            prod*=nums[i];
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0 && f==1) ans[i]=prod;
            if(f==0) ans[i]=prod/nums[i];
        }
        return ans;
    }
};