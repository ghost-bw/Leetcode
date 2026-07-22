class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> f;
        for (int x : nums) f[x]++;

        unordered_set<int> l;
        vector<int> ans;

        for (int x : nums) {
            l.insert(x);

            f[x]--;
            if (f[x] == 0) f.erase(x);

            ans.push_back(l.size() - f.size());
        }

        return ans;
    }
};