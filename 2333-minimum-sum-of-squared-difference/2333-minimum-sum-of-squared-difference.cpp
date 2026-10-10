class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> d(nums1.size());
        long long k = 1LL * k1 + k2, s = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            s += d[i];
            mx = max(mx, d[i]);
        }

        if (s <= k) return 0;

        int l = 0, r = mx;

        while (l < r) {
            int m = l + (r - l) / 2;
            long long need = 0;

            for (int x : d)
                need += max(0, x - m);

            if (need <= k)
                r = m;
            else
                l = m + 1;
        }

        long long ans = 0;

        for (int x : d) {
            int y = min(x, l);
            k -= max(0, x - l);
            ans += 1LL * y * y;
        }

        for (int i = 0; i < d.size() && k > 0; i++) {
            if (d[i] >= l && l > 0) {
                ans -= 1LL * l * l;
                ans += 1LL * (l - 1) * (l - 1);
                k--;
                d[i] = l - 1;
            }
        }

        return ans;
    }
};