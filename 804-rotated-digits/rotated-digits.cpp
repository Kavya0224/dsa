class Solution {
public:
    int rotatedDigits(int n) {
        int ct=0;
        for(int i=2;i<=n;i++){
            int temp=i;
            int f=0;
            int mirror=0;
            while(temp>0){
                int rem=temp%10;
                if(rem==7 || rem==3 || rem==4){
                    f=1;
                    break;
                }
                else if(rem==2 || rem==5 || rem==6 || rem==9) mirror=1;
                temp/=10;  
            }
            if(f==0 && mirror==1) ct++;
        }
        return ct;
    }
};