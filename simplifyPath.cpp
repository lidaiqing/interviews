class Solution {
public:
    string simplifyPath(string path) {
        stack<string> addr;
        string s;
        stringstream ss(path);
        char del = '/';
        while (getline(ss, s, del)) {
            if (s == "..") {
                if (!addr.empty()) addr.pop();
            } else if (s != "." && s != "") {
                addr.emplace(s);
            }
        }
        string res = "";
        stack<string> rev;
        while (!addr.empty()) {
            rev.emplace(addr.top());
            addr.pop();
        }
        if (rev.empty()) return "/";
        while (!rev.empty()) {
            res += "/" + rev.top();
            rev.pop();
        }
        return res;
    }
};
