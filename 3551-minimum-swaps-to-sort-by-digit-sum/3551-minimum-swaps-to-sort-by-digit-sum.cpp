class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> order;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            order.push_back({sum, nums[i], i});
        }

        sort(order.begin(), order.end());

        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            target[i] = get<2>(order[i]);
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || target[i] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[j];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};