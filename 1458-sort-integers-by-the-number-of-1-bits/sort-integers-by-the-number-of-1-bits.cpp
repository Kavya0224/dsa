class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());;
        vector<pair<int,int>> one(n);
        for(int i=0;i<n;i++){
            one[i].first=__builtin_popcount(arr[i]);
            one[i].second=arr[i];
        }
        sort(one.begin(),one.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i]=one[i].second;
        return ans;
    }
};