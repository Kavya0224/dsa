class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<long,long> mp;
        int n=nums.size();
        int ct=0;
        for(int i=0;i<n;i++){
            int need=k-nums[i];
            if(need>0 && mp.find(need)!=mp.end() && mp[need]>0){
                ct++;
                mp[need]--;
            }
            else mp[nums[i]]++;
        }
        return ct;
    }
};