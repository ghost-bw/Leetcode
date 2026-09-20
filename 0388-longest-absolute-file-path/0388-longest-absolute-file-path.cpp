class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> path(1, 0);
        int ans = 0;
        stringstream ss(input);
        string s;
        while (getline(ss, s)) {
            int level = 0;
            while (level < s.size() && s[level] == '\t')
                level++;
            string name = s.substr(level);
            path.resize(level + 1);
            int cur = path[level] + name.size();
            if (name.find('.') != string::npos) {
                ans = max(ans, cur);
            } else {
                path.push_back(cur + 1);
            }
        }

        return ans;
    }
};