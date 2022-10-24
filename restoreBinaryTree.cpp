Tree<int> * subTree(vector<int> & in, int inst, int inend, vector<int> & pre, int prest, int preend){
    if (inend < inst || preend < prest) return nullptr;
    Tree<int> * root = new Tree<int>(pre[prest]);
    int rootVal = pre[prest];
    int ix = inst;
    while (in[ix] != rootVal) ix++;
    int sz = ix - inst;
    root->left = subTree(in, inst, ix - 1, pre, prest + 1, prest + sz);
    root->right = subTree(in, ix + 1, inend, pre, prest + 1 + sz, preend);
    return root;
}

Tree<int> * solution(vector<int> inorder, vector<int> preorder) {
    return subTree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
}
