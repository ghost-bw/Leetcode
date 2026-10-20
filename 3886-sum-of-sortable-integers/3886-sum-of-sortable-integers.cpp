class Solution {
public:
    bool isRotable(vector<int> &vec1,vector<int>& vec2){
        if (vec1.size() != vec2.size()) return false;
        if (vec1.empty()) return true;
        vector<int>target=vec2;
        target.insert(end(target),begin(vec2),end(vec2));
        auto it = search(target.begin(), target.end(), vec1.begin(), vec1.end());
    
        // If it doesn't reach the end, the pattern was found
         return it != target.end();
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        int res=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0)continue;
            bool valid=true;
            for(int start=0;start<n;start+=k){
                vector<int>vec1(begin(nums)+start,begin(nums)+start+k);
                vector<int>vec2(begin(sorted)+start,begin(sorted)+start+k);
                if(!isRotable(vec1,vec2)){
                    valid=false;
                    break;
                }
            }
            if(valid)res+=k;
        }
        return res;
    }
};