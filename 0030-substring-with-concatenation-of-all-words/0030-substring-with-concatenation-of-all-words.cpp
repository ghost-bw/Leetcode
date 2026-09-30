class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), m = words.size(), len = words[0].size();

        unordered_map<string, int> need;

        for (auto &w : words)
            need[w]++;

        for (int start = 0; start < len; start++) {
            int l = start, r = start, cnt = 0;
            unordered_map<string, int> have;

            while (r + len <= n) {
                string word = s.substr(r, len);
                r += len;

                if (!need.count(word)) {
                    have.clear();
                    cnt = 0;
                    l = r;
                    continue;
                }

                have[word]++;
                cnt++;

                while (have[word] > need[word]) {
                    string left = s.substr(l, len);
                    have[left]--;
                    l += len;
                    cnt--;
                }

                if (cnt == m) {
                    ans.push_back(l);

                    string left = s.substr(l, len);
                    have[left]--;
                    l += len;
                    cnt--;
                }
            }
        }

        return ans;
    }
};