class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>&matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int t = 0, b = n - 1;
        int l = 0, r = m - 1;

        while (t <= b && l <= r) {
            for (int j = l; j <= r; j++)
                ans.push_back(matrix[t][j]);
            t++;

            for (int i = t; i <= b; i++)
                ans.push_back(matrix[i][r]);
            r--;

            if (t <= b) {
                for (int j = r; j >= l; j--)
                    ans.push_back(matrix[b][j]);
                b--;
            }

            if (l <= r) {
                for (int i = b; i >= t; i--)
                    ans.push_back(matrix[i][l]);
                l++;
            }
        }

        return ans;
    }
};