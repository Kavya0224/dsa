class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>=n) return false;
            freq[nums[i]]++;
            if(nums[i]!=n-1 && freq[nums[i]]>1) return false;
        }
        if(freq[n-1]!=2) return false;
        return true;
    }
};