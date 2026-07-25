class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string> ans;
        unordered_map<string, int> prev;

        for (string word : words) {
            string key = word;
            sort(key.begin(), key.end());

            if (prev.empty() || prev.find(key) == prev.end()) {
                ans.push_back(word);
                prev.clear();      // Forget older groups
                prev[key] = 1;     // Remember only previous kept word
            }
        }

        return ans;
    }
};