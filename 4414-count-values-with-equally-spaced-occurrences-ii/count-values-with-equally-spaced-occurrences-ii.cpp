class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int ct=0;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        for(auto it:mp){
            if(it.second.size()<3) continue;
            int diff=it.second[1]-it.second[0];
            int f=1;
            for(int i=2;i<it.second.size();i++){
                if(diff!=it.second[i]-it.second[i-1]){
                    f=0;
                    break;
                }
            }
            if(f==1) ct++;
        }
        return ct;
    }
};