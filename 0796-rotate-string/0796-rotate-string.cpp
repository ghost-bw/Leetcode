class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length()!=s.length()) return false;
        s=s.append(s);
        if(s.find(goal)!=std::string::npos)return true;
        return false;
    }
};