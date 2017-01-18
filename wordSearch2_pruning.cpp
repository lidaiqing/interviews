class Solution {
// using one time search trie tree. Once it finds a word, reset isLeaf to false
public:

    Solution()

    {

        TrieTree_ = new TrieNode();

    }

    void findWordsHelper(vector<vector<char>>& board, string curWord, int r, int c, vector<string>& result)

    {

        if (Search(curWord))

        {

            result.emplace_back(curWord);

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

        vector<string> result;

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

        

        return result;

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

        if (cur->isLeaf) {

            cur->isLeaf = false;

            return true;

        }

        return false;

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
