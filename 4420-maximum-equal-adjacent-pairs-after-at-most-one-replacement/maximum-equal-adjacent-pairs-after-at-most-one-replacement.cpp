class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {

        int n = nums.size();

        int count = 0; 
        int extra = 0; 

        map<pair<int,int>,int> mpp;

        for( int i = 0 ; i < n-1 ; i++ ){
            if( nums[i] == nums[i+1] ) count++;
            else {

                int x = min(nums[i],nums[i+1]);
                int y = max(nums[i],nums[i+1]);
                mpp[{x,y}]++;
                extra = max(extra,mpp[{x,y}]);

            }
        }

        return count+extra ;
        
    }
};