class Solution {
public:
    void binary(int n,string& s){
        while(n>0){
            int rem=n%2;
            s+=to_string(rem);
            n/=2;
        }

    }
    unsigned long long convert(string& bin){
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) + (bin[i] - '0');
        }
        return ans;
    }
    int reverseBits(int n) {
        string s="";
        binary(n,s);
        string bin="00000000000000000000000000000000";
        int i=0;
        while(i<s.size()){
            bin[i]=s[i];
            i++;
        }
        return convert(bin);
    }
};