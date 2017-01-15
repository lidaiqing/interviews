class Vector2D {
// deal with empty case
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin(), iEnd = vec2d.end();
        j = 0;
    }

    int next() {
        hasNext();
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size())
            i++, j = 0;
        return i != iEnd;
    }
private:
    vector<vector<int>>::iterator i, iEnd;
    int j;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
