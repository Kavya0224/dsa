class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        int sum=0;
        string s="";
        while(n>0){
            int rem=n%10;
            if(rem!=0){
                s+=to_string(rem);
                sum+=rem;
            }
            n/=10;
        }
        reverse(s.begin(),s.end());
        n=stoi(s);
        return 1LL*sum*n;
    }
};