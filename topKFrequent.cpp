class Solution {
// key idea: use bucket sort to sort frequency O(n)
// use cnt to count frequency
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> cnt;

        for (auto &n : nums)

            cnt[n]++;

        vector<vector<int> > bucket(nums.size()+1);

        for (auto &n : cnt)

        {

            if (bucket[n.second].size() == 0) {

                vector<int> tmp{n.first};

                bucket[n.second] = tmp;

            } else {

                bucket[n.second].emplace_back(n.first);

            }

        }

        vector<int> res;

        for (int i = nums.size(); i >= 1; i--)

        {

            if (bucket[i].size() != 0) {

                for (auto n : bucket[i])

                {

                    res.emplace_back(n);

                    if (res.size() == k) return res;

                }

            }

        }

        return res;

    }

};
