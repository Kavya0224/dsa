class Solution {
public:
    vector<int> evenOddBit(int n) {
        int ct=0;
        int odd=0,even=0;
        while(n>0){
            int bit=n%2;
            n/=2;
            if(bit==1){
                if(ct%2==0) even++;
                else odd++;
            }
            ct++;
        }
        return {even,odd};
    }
};