class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = (int)nums.size();
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            const int min_sum = nums[i] + nums[i + 1] + nums[i + 2];
            if (min_sum > target) {
                if (min_sum - target < abs(closest - target)) {
                    closest = min_sum;
                }
                break;
            }

            const int max_sum = nums[i] + nums[n - 2] + nums[n - 1];
            if (max_sum < target) {
                if (target - max_sum < abs(closest - target)) {
                    closest = max_sum;
                }
                continue;
            }

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                const int sum = nums[i] + nums[l] + nums[r];

                if (sum == target) return target;

                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum < target) {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                } else {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }

        return closest;
    }
};