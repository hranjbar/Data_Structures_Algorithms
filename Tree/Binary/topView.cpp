/*
Given a pointer to the root of a binary tree, 
print the top view of the binary tree.
The tree as seen from the top the nodes, 
is called the top view of the tree.
For example :
   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4
Top View : 1 -> 2 -> 5 -> 6
*/

void topView(Node * root) {
        using T = pair<Node*, int>;
        using R = pair<int, int>;
        vector<R> ans;
        ans.push_back({root->data, 0});
        queue<T> q;
        q.push({root, 0});
        unordered_set<int> shadows;
        shadows.insert(0);
        while (!q.empty()) {
            T& el = q.front(); q.pop();
            Node* node = el.first;
            if (shadows.count(el.second) == 0) {
                shadows.insert(el.second);
                ans.push_back({node->data, el.second});
            }
            if (node->left) q.push({node->left, el.second - 1});
            if (node->right) q.push({node->right, el.second + 1});
        }
        sort(ans.begin(), ans.end(), [](R& a, R& b){
            return a.second < b.second;
        });
        for (R& el : ans) cout << el.first << " ";
}
