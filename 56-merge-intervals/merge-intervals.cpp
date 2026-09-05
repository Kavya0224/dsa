class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
            else return a[0]<b[0];
        });
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        while(i<intervals.size()){
            if(end>=intervals[i][0]){
               while(i<intervals.size()&&end>=intervals[i][0]){
                   end=max(end,intervals[i][1]);
                    i++;
                }
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
                i++;
            }
        }
        ans.push_back({start,end});
        return ans;
        
    }
       
};