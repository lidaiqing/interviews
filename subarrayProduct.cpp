class Solution {
// dynamic programming
public:

    int maxProduct(vector<int>& nums) {

        if (nums.size() == 0) return 0;

        int res = nums[0];

        vector<int> Max(nums.size(), INT_MIN);

        vector<int> Min(nums.size(), INT_MAX);

        Max[0] = nums[0];

        Min[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)

        {

            if (nums[i] >= 0) {

                Max[i] = max(nums[i], Max[i-1] * nums[i]);

                Min[i] = min(nums[i], Min[i-1] * nums[i]);

            } else {

                Max[i] = max(nums[i], Min[i-1] * nums[i]);

                Min[i] = min(nums[i], Max[i-1] * nums[i]);

            }

            res = max(res, Max[i]);

        }

        return res;

    }

};

class Solution {
// O(1) space solution, use pre and now to rotate nums
public:

    int maxProduct(vector<int>& nums) {

        if (nums.size() == 0) return 0;

        int maxNumPre = nums[0];

        int minNumPre = nums[0];

        int maxRes = nums[0];

        int maxNumNow, minNumNow;

        for (int i = 1; i < nums.size(); i++)

        {

            maxNumNow = max(nums[i], max(nums[i] * maxNumPre, nums[i] * minNumPre));

            minNumNow = min(nums[i], min(nums[i] * minNumPre, nums[i] * maxNumPre));

            maxRes = max(maxRes, max(maxNumNow, minNumNow));

            maxNumPre = maxNumNow;

            minNumPre = minNumNow;

        }

        return maxRes;

    }

};
