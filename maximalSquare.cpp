class Solution {
// idea: dp[i][j] is the maximal square size we can get at point(i, j)
// the state function make sure top-left, top, and left are all square
// if matrix[i][j] is 0, dpi][j] = 0
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_size = 0;
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int dp[m+1][n+1] = {0};
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            max_size = max(max_size, dp[0][i]);
        }
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = matrix[i][0] - '0';
            max_size = max(max_size, dp[i][0]);
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j< n; j++)
            {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    max_size = max(dp[i][j], max_size);
                }
            }
        }
        return max_size * max_size;
    }
};
