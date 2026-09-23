class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ct=0;
        for(int i=0;i<intervals.size();i++){
            int a=intervals[i][0],b=intervals[i][1];
            for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<=b) ct++;
                else break;
            }
        }
        return ct;
    }
};