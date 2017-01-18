class Solution {
// divide and conquer
// maintain four variables: sum, max sum, max left sum, max right sum
// sum = left.sum + right.sum
// max sum = max(left.maxsum, right.maxsum, left.max right sum + right. max left sum
// max left sum = max(left.maxsum, left.sum + right.maxleft)
// max right sum = max(right.maxsum, right.sum + left.maxright)
public:

    struct Res {

        int sum, maxSum, lMax, rMax;

        Res(int _sum, int _maxSum, int _lMax, int _rMax) : sum(_sum), maxSum(_maxSum), lMax(_lMax), rMax(_rMax) {}

    };

    Res maxSubArrayHelper(vector<int>& nums, int l, int r)

    {

        if (l == r) {

            return {nums[l],nums[l],nums[l],nums[l]}; // base case

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
// if cur_sum is less than 0, there is no good to keep it, reset it to 0
// but remember to update result dut to negative values
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

