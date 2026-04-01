class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<pair<int, pair<int, pair<char, int>>>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {positions[i], {healths[i], {directions[i], i}}};
        }
        
        sort(arr.begin(), arr.end());
        
        stack<pair<int, pair<int, pair<char, int>>>> st;
        
        for (int i = 0; i < n; i++) {
            int pos = arr[i].first;
            int h = arr[i].second.first;
            char d = arr[i].second.second.first;
            int idx = arr[i].second.second.second;
            
            if (d == 'R') {
                st.push({pos, {h, {d, idx}}});
            } 
            else {
                while (!st.empty() && st.top().second.second.first == 'R' && h > 0) {
                    int topPos = st.top().first;
                    int topH = st.top().second.first;
                    char topD = st.top().second.second.first;
                    int topIdx = st.top().second.second.second;
                    st.pop();
                    
                    if (topH > h) {
                        topH--;
                        h = 0;
                        st.push({topPos, {topH, {topD, topIdx}}});
                    } 
                    else if (topH < h) {
                        h--;
                    } 
                    else {
                        h = 0;
                    }
                }
                
                if (h > 0) {
                    st.push({pos, {h, {d, idx}}});
                }
            }
        }
        
        vector<pair<int, int>> temp;
        while (!st.empty()) {
            temp.push_back({st.top().second.second.second, st.top().second.first});
            st.pop();
        }
        
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        for (auto &it : temp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};