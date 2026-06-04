class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ct = 0;

        for (int i = num1; i <= num2; i++) {

            string s = to_string(i);
            bool ok = true;

            // a number with length <=2 cannot be wavy
            if (s.size() <= 2) continue;

            for (int j = 1; j < s.size() - 1; j++) {
                if (((s[j] > s[j-1] && s[j] > s[j+1]) ||
                      (s[j] < s[j-1] && s[j] < s[j+1]))) {
                    ct++;
                }
            }

           
        }

        return ct;
    }
};
