class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n=nums2.size();
        int m=nums1.size();
        int ans=0;
        while(j<n && i<m){
            if(i<=j && nums1[i]<=nums2[j]){
                ans=max(ans,j-i);
                j++;
            }
            else if(i==j){
                i++;
                j++;
            }
            else i++;
        }
        return ans;
    }
};