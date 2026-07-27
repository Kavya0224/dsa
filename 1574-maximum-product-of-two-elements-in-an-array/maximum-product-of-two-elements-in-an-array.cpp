class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=0,sec_mx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                sec_mx=mx;
                mx=nums[i];
            }
            else if(nums[i]>sec_mx){
                sec_mx=nums[i];
            }
        }
        return (mx-1)*(sec_mx-1);
    }
};