class Solution {
public:
    void perm(vector<int> arr, vector<vector<int>>& ans, int ind) {
        if(ind == arr.size()) {
            ans.push_back(arr);
            return;
        }

        for(int i = ind; i < arr.size(); i++) {

    swap(arr[i], arr[ind]);

    if((arr[ind] % (ind + 1)) != 0 &&
       ((ind + 1) % arr[ind]) != 0){
        swap(arr[i], arr[ind]);   // Backtrack
        continue;
    }

    perm(arr, ans, ind + 1);

    swap(arr[i], arr[ind]);       // Backtrack
}
    }

    int countArrangement(int n) {
        vector<vector<int>> ans;
        vector<int> arr;

        for(int i = 1; i <= n; i++)
            arr.push_back(i);

        perm(arr, ans, 0);

        return ans.size();
    }
};