class Solution {
// Dynamic Programming
public:

    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        bool can[n] = {false};

        unordered_set<string> Dict;

        for(auto & s : wordDict) Dict.emplace(s);

        for (int i = 0; i < n; i++)

        {

            for (int j = i; j >= 0; j--)

            {

                if (j == 0 || can[j-1]) {

                    string word = s.substr(j, i - j + 1);

                    if (Dict.find(word) != Dict.end()) {

                        //cout << word << endl;

                        can[i] = true;

                        break;

                    }

                }

            }

        }

        return can[n-1];

    }

};
