class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> s;

        int n = digits.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;

                    if(digits[i]==0) continue;        // no leading zero
                    if(digits[k]%2!=0) continue;     // must be even

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    s.insert(num);
                }
            }
        }

        vector<int> ans(s.begin(), s.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
