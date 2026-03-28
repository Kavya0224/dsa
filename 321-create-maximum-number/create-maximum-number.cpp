class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> st;

        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    bool greaterVector(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size()) return true;
        if (i < a.size() && a[i] > b[j]) return true;
        return false;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greaterVector(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int n = nums1.size(), m = nums2.size();

        int start = max(0, k - m);
        int end = min(k, n);

        for (int x = start; x <= end; x++) {
            vector<int> a = maxSubsequence(nums1, x);
            vector<int> b = maxSubsequence(nums2, k - x);
            vector<int> candidate = merge(a, b);

            if (ans.empty() || candidate > ans) {
                ans = candidate;
            }
        }

        return ans;
    }
};