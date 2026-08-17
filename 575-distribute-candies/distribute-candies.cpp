class Solution {
public:
    int distributeCandies(vector<int>& arr) {
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++) s.insert(arr[i]);
        return min(s.size(),arr.size()/2);
    }
};