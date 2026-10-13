class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) nums[i]=abs(nums[i]);
        sort(nums.begin(),nums.end());
        int st=0,end=nums.size()-1;
        long long ans=0;
        while(st<end){
            ans-=(nums[st]*nums[st]);
            ans+=(nums[end]*nums[end]);
            st++;
            end--;
        }
        if(st==end) ans+=(nums[st]*nums[st]);
        return ans;
    }
};