class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++)
        {
            if (!isdigit(input[i])) {
                for(int a : diffWaysToCompute(input.substr(0, i))) {
                    for(int b : diffWaysToCompute(input.substr(i+1))) {
                        res.emplace_back(input[i] == '+' ? a + b : input[i] == '-' ? a - b : a * b);
                    }
                }
            }
        }
        return res.size() ? res : vector<int>{atoi(input.c_str())};
    }
};
