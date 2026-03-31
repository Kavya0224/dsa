class Solution {
public:
    string addStrings(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        string ans="";
        int carry=0;
        while(i>=0 && j>=0){
            int a=s[i]-'0';
            int b=t[j]-'0';
            int num=a+b+carry;
            int rem=(num)%10;
            ans+=to_string(rem);
            carry=num/10;
            i--; j--;
        }
        while(i>=0){
            int a=s[i]-'0';
            int num=a+carry;
            int rem=(num)%10;
            ans+=to_string(rem);
            carry=num/10;
            i--;
        }
        while(j>=0){
            int b=t[j]-'0';
            int num=b+carry;
            int rem=(num)%10;
            ans+=to_string(rem);
            carry=num/10;
            j--;
        }
        if(carry!=0) ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};