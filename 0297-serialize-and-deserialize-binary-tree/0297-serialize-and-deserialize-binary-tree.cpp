class Codec {
public:
    using tn = TreeNode*;

    string serialize(TreeNode* root) {
        if (root == nullptr) return "n";
        string s = "";
        queue<tn> q;
        q.push(root);

        // \U0001f539 changed this line (was root->val + '0')
        s += to_string(root->val);
        s.push_back(' '); // minimal separator so we can decode multi-digits

        while (!q.empty()) {
            tn t = q.front();
            q.pop();
            if (t == nullptr) continue;

            if (t->left) {
                q.push(t->left);
                s += to_string(t->left->val);   // \U0001f539 changed this line
                s.push_back(' ');
            } else {
                s.push_back('n');
                s.push_back(' ');
            }

            if (t->right) {
                q.push(t->right);
                s += to_string(t->right->val);  // \U0001f539 changed this line
                s.push_back(' ');
            } else {
                s.push_back('n');
                s.push_back(' ');
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "n") return nullptr;
        vector<string> vals;
        string cur = "";
        for (char c : data) {
            if (c == ' ') {
                if (!cur.empty()) vals.push_back(cur);
                cur.clear();
            } else cur.push_back(c);
        }
        if (!cur.empty()) vals.push_back(cur);

        int i = 0, c = 1;
        tn root = new TreeNode(stoi(vals[0]));
        map<int, tn> mp;
        mp[0] = root;

        while (c < vals.size()) {
            tn curr = mp[i];
            if (curr == nullptr) { i++; continue; }

            if (vals[c] != "n") {
                curr->left = new TreeNode(stoi(vals[c]));
                mp[c] = curr->left;
            } else mp[c] = nullptr;
            c++;

            if (c < vals.size() && vals[c] != "n") {
                curr->right = new TreeNode(stoi(vals[c]));
                mp[c] = curr->right;
            } else if (c < vals.size()) mp[c] = nullptr;
            c++;
            i++;
        }
        return root;
    }
};
