class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int i=0;
        int n=plants.size();
        int w=capacity;
        int ct=0;
        while(i<n){
            if(plants[i]<=w){
                w-=plants[i];
                ct++;
                i++;
            }
            else{
                ct+=(i)*2;
                w=capacity;
            }
        }
        return ct;
    }
};