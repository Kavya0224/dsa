class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=0;
        for(int i=1;i<nums.size();i++){
            int j=i-1;
            while(j>=0){
                if(nums[i]-nums[j]==1){
                    mx=max(mx,i-j+1);
                }
                j--;
            }
        }
        return mx;
    }
};