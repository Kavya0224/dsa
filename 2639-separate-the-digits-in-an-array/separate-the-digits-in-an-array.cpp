class Solution {
public:
     
        vector<int> ans;
    void helper(int n){
        if(n==0) return;
        helper(n/10);
        
            ans.push_back(n%10);
      
    }
    vector<int> separateDigits(vector<int>& nums) {
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) ans.push_back(nums[i]);
            
                helper(nums[i]);
            
        }
        return ans;;
    }
};