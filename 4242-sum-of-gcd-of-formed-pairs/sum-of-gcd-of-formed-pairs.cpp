class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n=nums.size();
        int mx=0;
        
        vector<long long> pre(n);
        for(long long i=0;i<n;i++){
            mx=max(mx,nums[i]);
            pre[i]=gcd(mx,nums[i]);
        }
        sort(pre.begin(),pre.end());
        long long i=0,j=n-1;
        long long sum=0;
        while(i<j){
            long long temp=gcd(pre[i],pre[j]);
            sum+=temp;
            i++;
            j--;
        }
        return sum;
    }
};