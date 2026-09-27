class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        vector<vector<int>> arr;
        arr.push_back(tiles[0]);
        for (int i = 1; i < tiles.size(); i++) {
            if (tiles[i][0] <= arr.back()[1] + 1) {
                arr.back()[1] = max(arr.back()[1], tiles[i][1]);
            } else {
                arr.push_back(tiles[i]);
            }
        }

        int ans = 0;
        int currentCover = 0;
        int j = 0;

        for (int i = 0; i < arr.size(); i++) {
            int carpetEnd = arr[i][0] + carpetLen - 1;

            while (j < arr.size() && arr[j][1] <= carpetEnd) {
                currentCover += arr[j][1] - arr[j][0] + 1;
                j++;
            }

            if (j < arr.size() && arr[j][0] <= carpetEnd) {
                int partialCover = carpetEnd - arr[j][0] + 1;
                ans = max(ans, currentCover + partialCover);
            } else {
                ans = max(ans, currentCover);
            }

            currentCover -= (arr[i][1] - arr[i][0] + 1);
        }

        return ans;
    }
};