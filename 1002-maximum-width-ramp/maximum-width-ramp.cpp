class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        for(int i = 0 ; i <= n - 1 ; i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                st.push(i);
            }
        }

        int max_Width = 0;
        for(int j = n - 1 ; j > 0 ; j--){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                max_Width = max(max_Width , j - st.top());
                st.pop();
            }
        }
        return max_Width;
    }
};