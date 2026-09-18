

class Solution {
public:
    void duplicateZeros(std::vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        int left = 0;

        // Step 1: Count zeros that can fit into the modified array
        while (left < n - zeros) {
            if (arr[left] == 0) {
                // Edge case: A zero is at the boundary and its duplicate would fall out of bounds
                if (left == n - 1 - zeros) {
                    arr[n - 1] = 0; // Place it at the last index
                    n--;            // Reduce effective array boundary
                    break;
                }
                zeros++;
            }
            left++;
        }

        // Step 2: Backward pass to shift elements and duplicate zeros
        int lastIdx = n - 1 - zeros;
        for (int i = lastIdx; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + zeros] = 0;
                zeros--;
                arr[i + zeros] = 0;
            } else {
                arr[i + zeros] = arr[i];
            }
        }
    }
};
