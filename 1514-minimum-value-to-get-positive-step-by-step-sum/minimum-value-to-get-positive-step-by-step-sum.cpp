class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mn=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mn=min(mn,sum);
        }
        return abs(mn)+1;
    }
};