class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int d=discounts.size();
        int n=prices.size();
        double ans=0;
        for(int i=0;i<min(d,n);i++){
            double p=(prices[i]*(100-discounts[i]))/100.00;
            ans+=p;
        }
        if(d<n){
            for(int i=d;i<n;i++) ans+=prices[i];
        }
        return ans;
    }
};