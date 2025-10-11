class Solution {
public:
bool helper(int n,int pow,long long int no){
    if(no>n) return false;
    if(no==n) return true;
    return helper(n,pow+1,no*2);
}
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        return helper(n,1,2);
    }
};