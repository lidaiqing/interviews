class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_set<char> mp_set;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end()) {
                if (mp_set.find(t[i]) == mp_set.end())
                {
                    mp[s[i]] = t[i];
                    mp_set.emplace(t[i]);
                } else return false;
            }
            else {
                if (mp[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
