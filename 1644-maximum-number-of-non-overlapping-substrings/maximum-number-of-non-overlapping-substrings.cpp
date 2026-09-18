class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<pair<int,int>> arr(26,{-1,-1});
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a'].first==-1){
                arr[s[i]-'a'].first=i;
                arr[s[i]-'a'].second=i;
            }
            else arr[s[i]-'a'].second=i;
        }

        bool changed = true;
        while(changed) {
            changed = false;
            for(int i=0; i<26; i++){
                if(arr[i].first == -1) continue;
                for(int j=arr[i].first; j<=arr[i].second; j++){
                    int idx = s[j]-'a';
                    if(arr[idx].first < arr[i].first) {
                        arr[i].first = arr[idx].first;
                        changed = true;
                    }
                    if(arr[idx].second > arr[i].second) {
                        arr[i].second = arr[idx].second;
                        changed = true;
                    }
                }
            }
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == -1) return false; 
            if (b.first == -1) return true;
            return a.second < b.second; 
        });

        vector<string> ans;
        int last_end = -1;

        for(int i=0;i<26;i++){
            int a=arr[i].first;
            int b=arr[i].second;
            if(a==-1) break;

            if(a > last_end) {
                ans.push_back(s.substr(a, b - a + 1));
                last_end = b;
            }
        }
        return ans;
    }
};