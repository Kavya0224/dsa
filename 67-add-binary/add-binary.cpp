class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        string ans="";
        char nxt='0';
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(nxt=='1'){
                    ans+='1';
                }
                else{
                    ans+='0';
                    nxt='1';
                }
                i--; j--;
            }
            else if(a[i]=='1' || b[j]=='1'){
                if(nxt=='1'){
                    ans+='0';
                }
                else{
                    ans+='1';
                }
                i--; j--;
            }
            else{
                if(nxt=='1'){
                    ans+='1';
                    nxt='0';
                }
                else{
                    ans+='0';
                }
                i--; j--;
            }
        }
        while(i>=0){
            if(a[i]=='1'){
                if(nxt=='1') ans+='0';
                else{
                    ans+='1';
                    nxt='0';
                }
            }
            else{
                if(nxt=='1'){
                    ans+='1';
                    nxt='0';
                }
                else ans+='0';
            }
            i--;
        }
        while(j>=0){
            if(b[j]=='1'){
                if(nxt=='1'){
                    ans+='0';

                }
                else{
                    ans+='1';
                    nxt='0';
                }
            }
            else{
                if(nxt=='1') {
                    ans+='1';
                    nxt='0';
                }
                else ans+='0';
            }
            j--;
        }
        if(nxt=='1') ans+=nxt;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};