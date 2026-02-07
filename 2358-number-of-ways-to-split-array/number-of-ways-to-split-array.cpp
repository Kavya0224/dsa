class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n);
        pre[0]=nums[0];
        int ct=0;
        vector<long long> preEnd(n);
        preEnd[n-1]=nums[n-1];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        for(int i=n-2;i>=0;i--) preEnd[i]=preEnd[i+1]+nums[i];
        for(int i=0;i<n-1;i++){
            if(pre[i]>=preEnd[i+1]) ct++;
        }
        return ct;
    }
    
};