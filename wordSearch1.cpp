class Solution {
// key idea: use dfs + backtracking, no way to do memo search
// no revisit allowed
public:

    bool existHelper(vector<vector<char>>& board, string word, int r, int c, int cur)

    {

        if (cur == word.size() - 1) {

            return true;

        }

        int dr[] = {-1,1,0,0};

        int dc[] = {0,0,-1,1};

        for (int i = 0; i < 4; i++)

        {

            int rr = r + dr[i];

            int cc = c + dc[i];

            if (rr >= 0 && rr < board.size() && cc >= 0 && cc < board[0].size()) {

                if (board[rr][cc] == word[cur+1]) {

                    char old = board[rr][cc];

                    board[rr][cc] = '*';

                    if (existHelper(board, word, rr, cc, cur + 1)) return true;

                    board[rr][cc] = old;

                }

            }

        }

        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {

        if (board.size() == 0) return false;

        for (int i = 0; i < board.size(); i++)

        {

            for (int j = 0; j < board[0].size(); j++)

            {

                if (board[i][j] == word[0]) {

                    char old = board[i][j];

                    board[i][j] = '*'; // use it to mark visited

                    if (existHelper(board, word, i, j, 0)) return true;

                    board[i][j] = old;

                }

            }

        }

        return false;

    }

};
