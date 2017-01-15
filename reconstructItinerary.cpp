class Solution {
// use map to sort adj string, use dfs backtracking to find valid solution
public:
    bool findItineraryHelper(int n, string cur, vector<string>& res)
    {
        if (res.size() == n) {
            return true;
        }
        for (auto &p : mp[cur])
        {
            if (p.second > 0) {
                p.second--;
                res.emplace_back(p.first);
                if (findItineraryHelper(n, p.first, res)) return true;
                res.pop_back();
                p.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto & t : tickets)
        {
            mp[t.first][t.second]++;
        }
        vector<string> res;
        string start = "JFK";
        res.emplace_back(start);
        findItineraryHelper(tickets.size() + 1, start, res);
        return res;
    }
private:
    unordered_map<string, map<string, int> > mp;
};
