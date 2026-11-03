class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            moves+=maxi-nums[i];
        }
        return moves;
    }
};