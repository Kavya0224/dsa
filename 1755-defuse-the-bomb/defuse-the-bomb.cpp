class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);
        int n=code.size();
        if(k==0) return ans;
        else if(k>0){
            for(int i=0;i<code.size();i++){
                int temp=k;
                int j=(i+1)%n;
                int sum=0;
                while(temp--){
                    j=j%n;
                    sum+=code[j];
                    j++;
                }
                ans[i]=sum;
            }
        }
        else{
            for(int i=0;i<code.size();i++){
                int temp=k;
                int j=i-1;
                if(j<0) j=n-1;
                int sum=0;
                temp=-temp;
                while(temp--){
                    if(j<0) j=n-1;
                    sum+=code[j];
                    j--;
                }
                ans[i]=sum;
            }
        }
        return ans;
    }
};