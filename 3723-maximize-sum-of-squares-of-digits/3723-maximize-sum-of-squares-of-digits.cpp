#include <string>
#include <algorithm>

class Solution {
public:
    string maxSumOfSquares(int num, int s) {
      if (s == 0) return (num == 1) ? "0" : "";
        
        if (s > 9 * num) return "";

        string result = "";

        for (int i = 0; i < num; i++) {
            if (s >= 9) {
                result += '9';
                s -= 9;
            } else {
                result += to_string(s);
                s = 0;
                while (result.length() < num) {
                    result += '0';
                }
                break;
            }
        }
        return result;
    }
};
