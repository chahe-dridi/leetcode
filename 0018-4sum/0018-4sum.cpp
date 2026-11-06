class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = (int)nums.size();
        if (n < 4) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        const long long t = target;

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > t) break;
            if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < t) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > t) break;
                if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < t) continue;

                int l = j + 1;
                int r = n - 1;
                const long long rem = t - (long long)nums[i] - nums[j];

                while (l < r) {
                    const long long sum = (long long)nums[l] + nums[r];

                    if (sum < rem) {
                        ++l;
                    } else if (sum > rem) {
                        --r;
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});

                        const int lv = nums[l];
                        const int rv = nums[r];

                        while (l < r && nums[l] == lv) ++l;
                        while (l < r && nums[r] == rv) --r;
                    }
                }
            }
        }

        return res;
    }
};