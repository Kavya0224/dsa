class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visStep(n, 0); 
        int currentStep = 1;
        int maxCycle = -1;

        for (int i = 0; i < n; ++i) {
            if (visStep[i] > 0) continue;

            int startStep = currentStep;
            int curr = i;

            while (curr != -1 && visStep[curr] == 0) {
                visStep[curr] = currentStep++;
                curr = edges[curr];
            }

            if (curr != -1 && visStep[curr] >= startStep) {
                maxCycle = max(maxCycle, currentStep - visStep[curr]);
            }
        }

        return maxCycle;
    }
};