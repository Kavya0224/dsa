#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
    long long countPermutations(const vector<int>& freq, int totalLen, long long kCap) {
        long long ans = 1;
        int currentLen = 0;
        
        for (int count : freq) {
            for (int j = 1; j <= count; ++j) {
                currentLen++;
                ans = ans * currentLen / j;
                if (ans > kCap) return kCap + 1; 
            }
        }
        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> fullFreq(26, 0);
        for (char c : s) {
            fullFreq[c - 'a']++;
        }

        vector<int> halfFreq(26, 0);
        char midChar = 0;
        for (int i = 0; i < 26; ++i) {
            halfFreq[i] = fullFreq[i] / 2;
            if (fullFreq[i] % 2 != 0) {
                midChar = 'a' + i;
            }
        }

        int halfLen = s.size() / 2;
        if (countPermutations(halfFreq, halfLen, k) < k) {
            return "";
        }

        string firstHalf = "";
        long long currentK = k;

        for (int i = 0; i < halfLen; ++i) {
            int remainingLen = halfLen - 1 - i;
            
            for (int c = 0; c < 26; ++c) {
                if (halfFreq[c] == 0) continue;
                halfFreq[c]--;
                long long permutations = countPermutations(halfFreq, remainingLen, currentK);

                if (currentK <= permutations) {
                    firstHalf += (char)('a' + c);
                    break;
                } else {
                    currentK -= permutations;
                    halfFreq[c]++; 
                }
            }
        }

        string result = firstHalf;
        if (s.size() % 2 != 0) {
            result += midChar;
        }
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        result += secondHalf;

        return result;
    }
};