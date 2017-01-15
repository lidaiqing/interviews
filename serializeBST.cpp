/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
// serialize to preorder, use range to deserialize it
public:
    void serializeHelper(TreeNode* root, string& s)
    {
        if (root == NULL) return;
        s += to_string(root->val) + "#";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string send = "";
        serializeHelper(root, send);
        return send;
    }
    TreeNode* deserializeHelper(vector<int>& pre, int& ptr, int l, int r)
    {
        if (ptr >= pre.size()) return NULL;
        TreeNode* root = NULL;
        if (pre[ptr] > l && pre[ptr] < r) {
            root = new TreeNode(pre[ptr]);
            ptr++;
            root->left = deserializeHelper(pre, ptr, l, root->val);
            root->right = deserializeHelper(pre, ptr, root->val, r);
        }
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> pre;
        stringstream ss(data);
        string num;
        while (getline(ss, num, '#')) {
            if (num != "") pre.emplace_back(atoi(num.c_str()));
        }
        int ptr = 0;
        return deserializeHelper(pre, ptr, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
