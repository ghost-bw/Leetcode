#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int m) {
        if (m <= 0) return true;         
        int n = flowerbed.size();    
        for (int i = 0; i < n; i++) {
            if (flowerbed[i] == 0) {
                bool left_empty = (i == 0 || flowerbed[i - 1] == 0);
                bool right_empty = (i == n - 1 || flowerbed[i + 1] == 0);
                
                if (left_empty && right_empty) {
                    flowerbed[i] = 1;
                    m--;
                    if (m == 0) return true;
                }
            }
        }
        
        return m <= 0;
    }
};
