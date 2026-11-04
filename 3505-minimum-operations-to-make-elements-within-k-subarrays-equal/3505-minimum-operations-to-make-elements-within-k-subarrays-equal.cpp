
class BIT {
public:
    int n;
    vector<long long> t;

    BIT(int n) {
        this->n = n;
        t.assign(n + 1, 0);
    }

    void update(int i, long long v) {
        while (i <= n) {
            t[i] += v;
            i += i & -i;
        }
    }

    long long query(int i) {
        long long s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int kth(int k) {
        int idx = 0;
        int b = 1;

        while ((b << 1) <= n) b <<= 1;

        for (; b; b >>= 1) {
            int nxt = idx + b;

            if (nxt <= n && t[nxt] < k) {
                idx = nxt;
                k -= t[nxt];
            }
        }

        return idx + 1;
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int m = v.size();

        BIT cnt(m), sum(m);

        auto update = [&](int a, int d) {
            int id = lower_bound(v.begin(), v.end(), a) - v.begin() + 1;
            cnt.update(id, d);
            sum.update(id, 1LL * a * d);
        };

        vector<long long> cost(n - x + 1);
        long long total = 0;

        for (int i = 0; i < x; i++) {
            update(nums[i], 1);
            total += nums[i];
        }

        for (int i = 0; i <= n - x; i++) {
            int id = cnt.kth((x + 1) / 2);
            long long med = v[id - 1];

            long long c = cnt.query(id);
            long long s = sum.query(id);

            cost[i] = med * c - s + total - s - med * (x - c);

            if (i < n - x) {
                update(nums[i], -1);
                total -= nums[i];

                update(nums[i + x], 1);
                total += nums[i + x];
            }
        }

        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> cur(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);

            for (int i = 1; i <= n; i++) {
                cur[i] = cur[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    cur[i] = min(
                        cur[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(cur);
        }

        return prev[n];
    }
};
