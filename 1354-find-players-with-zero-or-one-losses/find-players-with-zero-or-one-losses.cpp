class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<matches.size();i++){
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        vector<int> win,lose;
        for(auto it:mp){
            if(it.second.second==0) win.push_back(it.first);
            if(it.second.second==1) lose.push_back(it.first);
        }
        sort(win.begin(),win.end());
        sort(lose.begin(),lose.end());
        return {win,lose};
    }
};