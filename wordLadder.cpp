class Solution {
// two end bfs
public:

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

        unordered_set<string> head, tail, *phead, *ptail;

        head.emplace(beginWord);

        tail.emplace(endWord);

        int dist = 2;

        while (!head.empty() && !tail.empty())

        {

            if (head.size() < tail.size()) {

                phead = &head;

                ptail = &tail;

            } else {

                phead = &tail;

                ptail = &head;

            }

            unordered_set<string> next;

            for (auto it = phead->begin(); it != phead->end(); it++)

            {

                string word = *it;

                wordList.erase(word);

                for (int i = 0; i < word.size(); i++)

                {

                    char c = word[i];

                    for (int j = 0; j < 26; j++)

                    {

                        word[i] = 'a' + j;

                        if (ptail->find(word) != ptail->end()) return dist;

                        if (wordList.find(word) != wordList.end()) {

                            next.emplace(word);

                            wordList.erase(word);

                        }

                    }

                    word[i] = c;

                }

            }

            dist++;

            swap(*phead,next);

        }

        return 0;

    }

};

class Solution {
// one bfs, delete wordList for visited
public:

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {

        wordList.emplace(endWord);

        queue<pair<string,int> > q;

        int res = 0;

        q.emplace(beginWord,1);

        wordList.erase(beginWord);

        while (!q.empty())

        {

            string t = q.front().first;

            int dis = q.front().second;

            q.pop();

            if (t == endWord) {

                res = dis;

                break;

            }

        

            for (int i = 0; i < t.size(); i++)

            {

                char c = t[i];

                for (int j = 0; j < 26; j++)

                {

                    t[i] = 'a' + j;

                    if (wordList.find(t) != wordList.end())

                    {

                        q.emplace(t, dis + 1);

                        wordList.erase(t);

                    }

                }

                t[i] = c;

            }

        }

        return res;

    }

};
