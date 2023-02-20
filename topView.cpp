void topView(Node * root) {
        queue<pair<Node *, int>> qu;
        qu.push({root, 0});
        int hd;
        map<int, int> mp;
        Node * node;
        while (!qu.empty()){
            node = qu.front().first;
            hd = qu.front().second;
            qu.pop();
            if (mp.count(hd)==0) mp[hd] = node->data;
            if (node->left) qu.push({node->left, hd-1});
            if (node->right) qu.push({node->right, hd+1});
        }
        for (auto & p : mp) cout<< p.second << " ";
    }
