class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string> a;
        for(int x:nums){
            a.push_back(to_string(x));
        }
        sort(a.begin(),a.end(),[](const string& a,const string& b){
            return a+b>b+a;
        });
        if(a[0]=="0")return "0";
        string ans;

        for (auto& x : a)
            ans += x;

        return ans;
    }
};