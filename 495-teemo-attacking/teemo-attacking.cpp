class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time=0;
        int n=timeSeries.size();
        for(int i=0;i<n;i++){
            int temp=timeSeries[i]+duration;
            if(i==n-1) time+=duration;
            else if(temp>=timeSeries[i+1]) time+=timeSeries[i+1]-timeSeries[i];
            else time+=duration;
        }
        return time;
    }
};