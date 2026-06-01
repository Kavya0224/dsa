class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int j=cost.size()-1;
        int sum=0;
        while(j>=1){
            sum+=cost[j-1]+cost[j];
           
            j-=3;
        }
        if(j==0) sum+=cost[j];
        return sum;
    }
};