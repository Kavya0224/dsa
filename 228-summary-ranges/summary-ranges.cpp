class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            int ct=0;
            string temp=to_string(nums[i]);
            while(i<n-1 && nums[i]+1==nums[i+1]){
                i++;
                ct++;
            }
            if(ct>0) ans.push_back(temp+"->"+to_string(nums[i]));
            else ans.push_back(temp);
        }
        return ans;
    }
};