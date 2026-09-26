class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp=nums2;
        sort(temp.rbegin(),temp.rend());
        sort(nums1.rbegin(),nums1.rend());
        unordered_map<int,vector<int>> mp;
        int st=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[st]>temp[i]) mp[temp[i]].push_back(nums1[st++]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums2[i])!=mp.end()){
                ans[i]=mp[nums2[i]].back();
                mp[nums2[i]].pop_back();
                if(mp[nums2[i]].size()==0) mp.erase(nums2[i]);
            }
            else ans[i]=nums1[st++];
        }
        return ans;






























































































































































    }
};