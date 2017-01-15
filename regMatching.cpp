class Solution {
// ket idea: base case, empty string can match  x* repeat 0 time
// two cases, use * then need to make sure previous char match and dp[i-1][j] match
// or do not use *
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        bool dp[m+1][n+1];
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = i > 1 && p[i-1] == '*' && dp[0][i-2];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else {
                    if (p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                    else if (p[j-1] == '*') {
                        dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                    }
                    else dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};
