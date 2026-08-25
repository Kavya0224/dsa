class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++) if(nums[i]%k==0) st.insert(nums[i]);
        int num=k;
        while(true){
            if(!st.count(num)) return num;
            num+=k;
        }
        return -1;
    }
};