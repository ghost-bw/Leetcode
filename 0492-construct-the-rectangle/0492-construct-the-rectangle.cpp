class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width=0;
        for(int i=1;i<=sqrt(area);i++){
            if(area%i==0){
                width=i;
            }
        }
        int length=area/width;
        return {length,width};
    }
};