class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans=0;
        for(int i=1;i<=nums.size()-pattern.size();i++){
            int f=0;
            for(int j=i;j<i+pattern.size();j++){
                if(pattern[j-i]==1 && nums[j]<=nums[j-1]){
                    f=1;
                    break;
                }
                if(pattern[j-i]==-1 && nums[j]>=nums[j-1]){
                    f=1;
                    break;
                }
                if(pattern[j-i]==0 && nums[j]!=nums[j-1]){
                    f=1;
                    break;
                }
            }
            if(f==0) ans++;
        }
        return ans;
    }
};