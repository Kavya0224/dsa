class Solution {
public:
    int concatenatedBinary(int n) {
        int i=2;
        long long num=1;
        int pow=2;
        int ct=0;
        int shift=2;
        n--;
        while(n--){
            if(pow==ct){
                shift++;
                pow<<=1;
                ct=0;
            }
            num=(num<<shift)%1000000007;
            num=(num+i)%1000000007;
            i++;
            ct++;
        }
        return num;
    }
};