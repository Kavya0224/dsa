class Solution {
public:
bool helper(int n,long long int no){
    if(no>n) return false;
    if(no==n) return true;
    return helper(n,no*4);
}
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        return helper(n,4);
    }
};