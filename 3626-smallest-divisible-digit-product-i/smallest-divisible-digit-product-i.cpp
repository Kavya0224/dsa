class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<n+10;i++){
            int p=1;
            int temp=i;
            while(temp>0){
                p*=(temp%10);
                temp/=10;
            }
            if(p%t==0) return i;
        }
        return -1;
    }
};