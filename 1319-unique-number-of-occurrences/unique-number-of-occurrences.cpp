class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[arr[i]]++;
        unordered_set<int> s;
        for(auto it:m){
            if(s.find(it.second)!=s.end()) return false;
            s.insert(it.second);
        }
        return true;

    }
};