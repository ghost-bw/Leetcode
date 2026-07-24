class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int m=dimensions[0].size();
        double maxdig=0;
        int maxarea=0;
       
        for(int i=0;i<n;i++){
                double dig=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
                int area=dimensions[i][0]*dimensions[i][1];
                if(dig>maxdig ){
                    maxarea=area;
                    maxdig=dig;
                }else if(maxdig==dig){
                    maxarea=max(maxarea,area);
                }
        }
        return maxarea;
    }
};