class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        string result = "";
        int n = s.length();
        int cycle_len = 2 * numRows - 2;

        for (int r = 0; r < numRows; ++r) {
            
            for (int i = 0; i + r < n; i += cycle_len) {
                
                result += s[i + r];
                if (r != 0 && r != numRows - 1) {
                    int second_index = i + cycle_len - r;
                    if (second_index < n) {
                        result += s[second_index];
                    }
                }
            }
        }
        
        return result;
    }
};
