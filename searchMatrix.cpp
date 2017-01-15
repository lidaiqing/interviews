class Solution {
// O(n) solution
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};

class Solution {
// O(logn) solution using binary search
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        int size = matrix[0].size();
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (matrix[m/size][m%size] == target) return true;
            if (matrix[m/size][m%size] > target) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
};
