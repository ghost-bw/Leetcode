class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
    unordered_map<int,int> mp;

    for (int x : arr) {
        int rem = ((x % k) + k) % k;   

        int need = (k - rem) % k;

        if (mp[need] > 0) {
            mp[need]--;
        } else {
            mp[rem]++;
        }
    }

    for (auto &p : mp)
        if (p.second != 0)
            return false;

    return true;
    }
};