class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> idx(101);
        int ct=0;
        for(int i=0;i<nums.size();i++) idx[nums[i]].push_back(i);
        for(int i=1;i<=100;i++){
            if(idx[i].size()!=3) continue;
            if(idx[i][1]-idx[i][0]==idx[i][2]-idx[i][1]) ct++;
        }
        return ct;
    }
};