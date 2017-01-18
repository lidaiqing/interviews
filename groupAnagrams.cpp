class Solution {
// sort each string and put it into hashtable
// O(nklog(k))
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string> > group;

        for (auto s : strs)

        {

            string t = s;

            sort(t.begin(), t.end());

            if (group.find(t) == group.end()) {

                vector<string> tmp;

                tmp.emplace_back(s);

                group[t] = tmp;

            } else {

                group[t].emplace_back(s);

            }

        }

        vector<vector<string> > ans;

        for (auto& g : group)

        {

            ans.emplace_back(g.second);

        }

        return ans;

    }

};
