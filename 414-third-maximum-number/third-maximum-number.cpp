class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        int ct=0;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++){
            int curr=nums[i];
            while(i+1<n && nums[i+1]==curr) i++;
            ct++;
            if(ct==3) return curr;
        }
        return nums[0];
    }
};