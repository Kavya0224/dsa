class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit=n&1;
        n=n>>1;
        while(n>0){
            int nxt=n&1;
            if(nxt==bit) return false;
            bit=nxt;
            n>>=1;
        }
        return true;
    }
};