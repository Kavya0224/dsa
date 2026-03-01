class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int l=0;
        double sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i-l+1==k){
                double temp=sum/k;
                ans=max(ans,temp);
                sum-=nums[l];
                l++;
            }

        }
        return ans;
    }
};