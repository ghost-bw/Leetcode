class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n));
        int t = 0, b = n - 1;
        int l = 0, r = n - 1;
        int x = 1;
        while (t <= b && l <= r) {
            for (int j = l; j <= r; j++)
                a[t][j] = x++;
            t++;
            for (int i = t; i <= b; i++)
                a[i][r] = x++;
            r--;

            if (t <= b) {
                for (int j = r; j >= l; j--)
                    a[b][j] = x++;
                b--;
            }

            if (l <= r) {
                for (int i = b; i >= t; i--)
                    a[i][l] = x++;
                l++;
            }
        }

        return a;
    }
};