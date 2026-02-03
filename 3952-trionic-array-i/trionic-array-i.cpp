class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int f=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                while(i<nums.size() && nums[i-1]<nums[i]){
                    i++;
                }
                i--;
                f++;
            }
            else if(nums[i]<nums[i-1]){
                if(f!=1) return false;
                while(i<nums.size() && nums[i]<nums[i-1]) i++;
                i--;
                f++;
            }
            else return false;
        }
        if(f!=3) return false;
        return true;
    }
};