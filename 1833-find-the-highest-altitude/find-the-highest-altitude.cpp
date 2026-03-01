class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=0;
        int n=gain.size();
        vector<int> alt(n+1,0);
        for(int i=0;i<n;i++){
            alt[i+1]=alt[i]+gain[i];
            mx=max(mx,alt[i]+gain[i]);
        }
        return mx;
    }
};