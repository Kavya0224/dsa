class Solution {
public:
    int convert(string s){
        int no=0;
        int ct=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                no=no+(1<<ct);
            }
            ct++;
        }
        return no;
    }
    int helper(int n){
        string s="";
        while(n>0){
            int rem=n%2;
            s+=to_string(rem);
            n/=2;
        }
        reverse(s.begin(),s.end());
        return convert(s);
    }
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        return helper(n);
    }
};