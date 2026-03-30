class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int> mp;
        int n=score.size();
        vector<int> arr=score;
        sort(score.rbegin(),score.rend());
        for(int i=0;i<n;i++){
            mp[score[i]]=i+1;
        }
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==1) ans.push_back("Gold Medal");
            else if(mp[arr[i]]==2) ans.push_back("Silver Medal");
            else if(mp[arr[i]]==3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mp[arr[i]]));
        }
        return ans;
    }
};