class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;
        
        vector<vector<int>> ans(r, vector<int>(c, 0));
        
        for (int k = 0; k < m * n; k++) {
            // Map the flat index 'k' straight into both matrices
            ans[k / c][k % c] = mat[k / n][k % n];
        }
        
        return ans;
    }
};
