class Solution {
// use dp to keep track of dup case
public:

    vector<int> diffWaysToComputeHelper(string input)

    {

        if (dp.find(input) != dp.end()) return dp[input];

        vector<int> res;

        for (int i = 0; i < input.size(); i++)

        {

            if (!isdigit(input[i])) {

                for (int a : diffWaysToComputeHelper(input.substr(0, i))) { // left part from 0 - i - 1

                    for (int b : diffWaysToComputeHelper(input.substr(i + 1))) { // right part from i + 1 to the end

                        res.emplace_back(input[i] == '+' ? a + b : input[i] == '-' ? a - b : a * b);

                    }

                }

            }

        }

        return dp[input] = res.empty() ? vector<int>{stoi(input.c_str())} : res; // tricky, if empty, input is a number

    }

    vector<int> diffWaysToCompute(string input) {

        return diffWaysToComputeHelper(input);

    }

private:

    unordered_map<string, vector<int>> dp;



};
