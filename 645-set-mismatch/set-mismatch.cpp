class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0),ans(2);
        for(int i=0;i<n;i++) freq[nums[i]]++;
        for(int i=1;i<=n;i++){
            if(freq[i]==2) ans[0]=i;
            if(freq[i]==0) ans[1]=i;
        }
        return ans;
    }
};