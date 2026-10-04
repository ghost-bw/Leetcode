class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        long long dx = c[1][0] - c[0][0];
        long long dy = c[1][1] - c[0][1];

        for(int i = 2; i < c.size(); i++) {
            long long x = c[i][0] - c[0][0];
            long long y = c[i][1] - c[0][1];

            if(x * dy != y * dx)
                return false;
        }

        return true;
    }
};