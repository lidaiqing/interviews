class Solution {
// Dynamic Programming
// O(n^2)
public:

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        bool can[n+1] = {false};
	can[0] = true;
        unordered_set<string> Dict;

        for(auto & s : wordDict) Dict.emplace(s);

        for (int i = 0; i < n; i++)

        {

            for (int j = i - 1; j >= 0; j--)

            {

                if (can[j]) {

                    string word = s.substr(j, i - j);

                    if (Dict.find(word) != Dict.end()) {

                        can[i] = true;

                        break;

                    }

                }

            }

        }

        return can[n];

    }

};

class Solution {
// same idea as the last solution but print all combinations
// for each break point, record index to the last points
// use backtracking to find all the combination
public:

    void wordBreakHelper(int cur, string& input, vector<vector<int>>& wordList, stack<string> tmp, vector<string>& res)

    {

        if (cur < 0) {

            string s = "";

            while (!tmp.empty())

            {

                if (s != "") s += " " + tmp.top();

                else s += tmp.top();

                tmp.pop();

            }

            res.emplace_back(s);

            return;

        }

        for (int i = 0; i < wordList[cur].size(); i++)

        {

            int idx = wordList[cur][i];

            string word = input.substr(idx, cur - idx + 1);

            tmp.emplace(word);

            wordBreakHelper(idx-1, input, wordList, tmp, res);

            tmp.pop();

        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        vector<vector<int> > wordList(n);

        unordered_set<string> Dict;

        for (auto& s : wordDict) Dict.emplace(s);

        bool can[n] = {false};

        

        for (int i = 0; i < n; i++)

        {

            for (int j = i; j >= 0; j--)

            {

                if (j == 0 || can[j-1]) {

                    string word = s.substr(j, i - j + 1);

                    if (Dict.find(word) != Dict.end()) {

                        if (wordList[i].size() == 0) {

                            vector<int> tmp;

                            wordList[i] = tmp;

                        }

                        wordList[i].emplace_back(j);

                        can[i] = true;

                    }

                }

            }

        }

        vector<string> res;

        stack<string> tmp;

        wordBreakHelper(n-1, s, wordList, tmp, res);

        return res;

        

    }

};
