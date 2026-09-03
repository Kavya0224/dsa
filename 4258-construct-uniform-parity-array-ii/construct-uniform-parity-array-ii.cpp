class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        bool odd=false;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,nums1[i]);
            if(nums1[i]%2==1) odd=true;
        }
        if(mn%2==1) return true;
        if(!odd) return true;
        return false;
    }
};