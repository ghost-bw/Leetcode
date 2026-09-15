class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ele=matrix[0][0];
        for(int i=0;i<n;i++){
            if(matrix[i][i]!=ele)return false;
        }
        return true;
    }
};