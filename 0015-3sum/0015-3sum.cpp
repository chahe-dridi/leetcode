class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = (int)nums.size();
        vector<vector<int>> res;
        res.reserve(64);

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;

            int l = i + 1;
            int r = n - 1;
            const int target = -nums[i];

            while (l < r) {
                const int sum = nums[l] + nums[r];
                if (sum < target) {
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    const int leftVal = nums[l];
                    const int rightVal = nums[r];
                    while (l < r && nums[l] == leftVal) ++l;
                    while (l < r && nums[r] == rightVal) --r;
                }
            }
        }

        return res;
    }
};