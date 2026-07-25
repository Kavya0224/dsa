class Solution {
public:
    int maxProduct(int n) {
        int mx=0;
        int sec_mx=0;
        while(n>0){
            int rem=n%10;
            if(rem>mx){
                sec_mx=mx;
                mx=rem;
            }
            else if(rem>sec_mx){
                sec_mx=rem;
            }
            n/=10;
        }
        return mx*sec_mx;
    }
};