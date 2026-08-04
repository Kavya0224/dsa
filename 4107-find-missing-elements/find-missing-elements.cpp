class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            mn=mn+1;
            while(nums[i]!=mn){
                ans.push_back(mn);
                mn++;
            }
        }
        return ans;
    }
};