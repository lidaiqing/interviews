class Solution {
// backtracking + Trie, search for prefix, aviod duplicated
public:

    Solution()

    {

        TrieTree_ = new TrieNode();

    }

    void findWordsHelper(vector<vector<char>>& board, string curWord, int r, int c, unordered_set<string>& result)

    {

        if (Search(curWord))

        {

            result.emplace(curWord);

        }

        

        int dr[] = {-1,1,0,0};

        int dc[] = {0,0,-1,1};

        for (int i = 0; i < 4; i++)

        {

            int rr = r + dr[i];

            int cc = c + dc[i];

            if (rr >= 0 && rr < board.size() && cc >= 0 && cc < board[0].size() && board[rr][cc] != '*')

            {

                string newWord = curWord + (char)board[rr][cc];

                if (HasPrefix(newWord))

                {

                    char old = board[rr][cc];

                    board[rr][cc] = '*';

                    findWordsHelper(board, newWord, rr, cc, result);

                    board[rr][cc] = old;

                }

            }

        }

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for (int i = 0; i < words.size(); i++)

            Insert(words[i]);

        int n = board.size(), m = board[0].size();

        unordered_set<string> result;

        for (int i = 0; i < n; i++)

        {

            for (int j = 0; j < m; j++)

            {

                string tmp;

                tmp.push_back(board[i][j]);

                if (HasPrefix(tmp))

                {

                    char old = board[i][j];

                    board[i][j] = '*';

                    findWordsHelper(board,tmp, i, j, result);

                    board[i][j] = old; 

                }

            }

        }

        vector<string> ans;

        for (auto s : result)

            ans.emplace_back(s);

        return ans;

    }

private:

    struct TrieNode

    {

        TrieNode()

        {

            isLeaf = false;

            for (int i = 0; i < 26; i++)

                children[i] = nullptr;

        }

        bool isLeaf;

        TrieNode* children[26];

    };

    void Insert(string& word)

    {

        TrieNode* cur = TrieTree_;

        int i = 0;

        while (i < word.size())

        {

            if (cur->children[word[i]-'a'] == nullptr)

                cur->children[word[i]-'a'] = new TrieNode();

            cur = cur->children[word[i]-'a'];

            i++;

        }

        cur->isLeaf = true;

    }

    bool Search(string& word)

    {

        TrieNode* cur = TrieTree_;

        int i = 0;

        while (i < word.size())

        {

            if (cur->children[word[i]-'a'] == nullptr) return false;

            cur = cur->children[word[i]-'a'];

            i++;

        }

        return cur->isLeaf;

    }

    bool HasPrefix(string& word)

    {

        TrieNode* cur = TrieTree_;

        int i = 0;

        while (i < word.size())

        {

            if (cur->children[word[i]-'a'] == nullptr) return false;

            cur = cur->children[word[i]-'a'];

            i++;

        }

        return true;

    }

    TrieNode* TrieTree_;

    vector<vector<int>> visited_;

};
