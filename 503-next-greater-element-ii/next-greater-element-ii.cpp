class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> s;
        int n=nums.size();
        vector<int> ans(n,-1);
        vector<bool> vis(n,false);
        s.push({0,nums[0]});
        for(int i=1;i<n;i++){
            while(!s.empty() && s.top().second<nums[i]){
                ans[s.top().first]=nums[i];
                s.pop();
            }
            s.push({i,nums[i]});
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().second<nums[i]){
                vis[s.top().first]=true;
                ans[s.top().first]=nums[i];
                s.pop();
            }
            if(!vis[i]) s.push({i,nums[i]});
        }
        return ans;
    }
};