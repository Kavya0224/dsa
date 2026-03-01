class Solution {
public:
    int compress(vector<char>& chars) {
        int n = (int)chars.size();
        int write = 0;  // where we write the compressed output
        int read = 0;   // where we read from

        while (read < n) {
            char ch = chars[read];
            int count = 0;

            // count the group
            while (read < n && chars[read] == ch) {
                read++;
                count++;
            }

            // write the character
            chars[write++] = ch;

            // write the count if > 1
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) chars[write++] = c;
            }
        }

        return write;
    }
};