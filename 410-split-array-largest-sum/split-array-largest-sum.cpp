class Solution {
    bool solve(vector<int>& nums, int k, int n){
        int sum=0, cnt=0;
        for(auto i: nums){
            if(sum+i>n){
                cnt++;
                sum = 0;
            }
            sum+=i;
        }
        return cnt<k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(), nums.end()), h=accumulate(nums.begin(), nums.end(), 0);
        while(l<h){
            int m=l+(h-l)/2;
            if(solve(nums, k, m)) h=m;
            else l=m+1;
        }
        return l;
    }
};