class Solution {
public:
    bool isanagram(string a, string b) {
        if (a.size() != b.size()) return false;

        unordered_map<char, int> mp;

        for (char c : a) mp[c]++;
        for (char c : b) mp[c]--;

        for (auto it : mp) {
            if (it.second != 0) return false;
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (string &w : words) {
            if (ans.empty() || !isanagram(ans.back(), w))
                ans.push_back(w);
        }

        return ans;
    }
};