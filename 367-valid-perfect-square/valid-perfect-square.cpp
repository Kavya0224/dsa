class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 0;
        int e = num;
        long long int  mid = s+(e-s)/2;
        long long int result;
        while(s<=e){
            result = mid*mid;
            if( result==num){
                return true;
            }if(result>num){
                e = mid-1;
            }else{
                s = mid+1;

            } mid = s+ (e-s)/2;
            if(s==mid&&num == mid*mid){
                return true;
            }
            
        }
     return false;
        
    }
};