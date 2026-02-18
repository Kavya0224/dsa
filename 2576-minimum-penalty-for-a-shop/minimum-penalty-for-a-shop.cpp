class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();

       vector<int> pre(n+1,0);
       for(int i=1;i<=n;i++){
        if(customers[i-1]=='Y') pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1]-1;
        }
    int idx=0;
    int mx=INT_MIN;
    for(int i=0;i<=n;i++){
        if(pre[i]>mx){
            mx=pre[i];
            idx=i;
        }
    }
    return idx;
    }
};