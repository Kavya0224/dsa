class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                int diff=i-m[nums[i]];
                m[nums[i]]=i;
                if(diff<=k) return true;
            }
            else m[nums[i]]=i;
        }
        return false;
    }
};