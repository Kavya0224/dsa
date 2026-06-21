class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ct=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                ct++;
                coins-=costs[i];
            }
            else break;
        }
        return ct;
    }
};