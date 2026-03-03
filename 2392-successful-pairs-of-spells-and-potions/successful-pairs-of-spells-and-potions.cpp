class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size());
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int st=0;
            int ans=0;
            int end=potions.size()-1;
            while(st<=end){
                int mid=st+(end-st)/2;
                if((long long)potions[mid]*spells[i]>=success){
                    ans=potions.size()-mid;
                    end=mid-1;
                }
                else st=mid+1;
            }
            res[i]=ans;
        }
        return res;
    }
};