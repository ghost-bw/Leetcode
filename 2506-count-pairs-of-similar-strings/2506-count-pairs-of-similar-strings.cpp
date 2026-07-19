class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        unordered_map<int, int> mp;
        int ans = 0;

        for (string &word : words) {
            int mask = 0;

            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }

            ans += mp[mask];
            mp[mask]++;
        }

        return ans;

        
    }
};