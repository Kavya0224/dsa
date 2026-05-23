class Solution {
public:
    bool check(vector<int>& nums) {
        int ct=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i] ){
                ct++;
            }
            
        }
         if( nums[0]<nums[nums.size()-1]){
                ct++;
            }
        if(ct>1){
            return false;
        }
        return true;
    }
};