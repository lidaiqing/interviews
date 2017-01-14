/*tion for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     TreeNode *left;

 *     TreeNode *right;

 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

 * };

 */

class Solution {

public:

    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == NULL) return {};

        vector<vector<int>> res;

        queue<pair<TreeNode*, int> > q;

        q.emplace(root, 0);

        while (!q.empty())

        {

            auto t = q.front();

            q.pop();

            if (t.second == res.size()) {

                vector<int> tmp{t.first->val};

                res.emplace_back(tmp);

            } else {

                res[t.second].emplace_back(t.first->val);

            }

            if (t.first->left) q.emplace(t.first->left, t.second + 1);

            if (t.first->right) q.emplace(t.first->right, t.second + 1);

        }

        return res;

    }

};
