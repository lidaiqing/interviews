class Solution {
// divide and conquer
public:

    struct Res {

        int sum, maxSum, lMax, rMax;

        Res(int _sum, int _maxSum, int _lMax, int _rMax) : sum(_sum), maxSum(_maxSum), lMax(_lMax), rMax(_rMax) {}

    };

    Res maxSubArrayHelper(vector<int>& nums, int l, int r)

    {

        if (l == r) {

            return {nums[l],nums[l],nums[l],nums[l]};

        }

        int m = (l + r) / 2;

        Res left = maxSubArrayHelper(nums, l, m);

        Res right = maxSubArrayHelper(nums, m + 1, r);

        return {left.sum + right.sum, max(left.maxSum, max(right.maxSum, left.rMax + right.lMax)), max(left.lMax,left.sum + right.lMax), max(right.rMax, right.sum + left.rMax)};

    }

    int maxSubArray(vector<int>& nums) {

        return maxSubArrayHelper(nums, 0, nums.size() - 1).maxSum;

    }

};

class Solution {
// dynamic programming
public:

    int maxSubArray(vector<int>& nums) {

        int res = INT_MIN;

        int cur_sum = 0;

        int i = 0;

        while (i < nums.size())

        {

            cur_sum += nums[i++];

            if (cur_sum < 0) {

                res = max(res, cur_sum);

                cur_sum = 0;

            } else {

                res = max(res, cur_sum);

            }

        }

        return res;

    }

};

