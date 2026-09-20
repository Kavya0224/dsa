class Solution {
public:
    vector<int> getFinalState(vector<int>& arr, int k, int multiplier) {
        for(int i=0;i<k;i++){
            int idx=0,mn=arr[0];
            for(int j=0;j<arr.size();j++){
                if(arr[j]<mn){
                    idx=j;
                    mn=arr[j];
                }
            }
            arr[idx]*=multiplier;
        }
        return arr;
    }
};