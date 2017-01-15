/**solution for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
// use # for empty and , for seperation
public:
    void serializeHelper(TreeNode* root, string& send)
    {
        if (root == NULL) {
            send += "#,";
            return;
        }
        send += to_string(root->val) + ",";
        serializeHelper(root->left, send);
        serializeHelper(root->right, send);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string send = "";
        serializeHelper(root, send);
        return send;
    }
    TreeNode* deserializeHelper(queue<string>& pre)
    {
        if (pre.empty()) return NULL;
        string s = pre.front();
        pre.pop();
        if (s == "#") return NULL;
        TreeNode* root = new TreeNode(atoi(s.c_str()));
        root->left = deserializeHelper(pre);
        root->right = deserializeHelper(pre);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string s;
        while (getline(ss, s, ',')) {
            q.emplace(s);
        }
        return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
