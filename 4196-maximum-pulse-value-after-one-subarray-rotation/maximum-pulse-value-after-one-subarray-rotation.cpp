class Solution {
public:
    long long kadane( vector<int>& nums ) {

        long long min_subarray_sum = 0 ;
        long long curr_sum = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( curr_sum > 0 ) curr_sum = nums[i] ;
            else curr_sum += nums[i] ;
            min_subarray_sum = min( min_subarray_sum , curr_sum ) ;
        }
        return min_subarray_sum ;
    }

    long long maxValue(vector<int>& nums) {

        int n = nums.size() ;
        long long totalSum = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( i % 2 == 1 ) nums[i] = -nums[i] ;
            totalSum += nums[i] ;

        }
        vector<int> even , odd ;
        for ( int i = 0 ; i < n-1 ; i += 2 ) even.push_back( nums[i] + nums[i+1] ) ;
        for ( int i = 1 ; i < n-1 ; i += 2 ) odd.push_back( nums[i] + nums[i+1] ) ;
        long long mini = min( kadane(even) , kadane(odd) ) ;
        return totalSum - 2*mini ;
    }
};