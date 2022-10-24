Tree<int> * subTree(vector<int> & in, vector<int>::iterator inst, vector<int>::iterator inend, vector<int> & pre, vector<int>::iterator prest, vector<int>::iterator preend){
    if (distance(inst, inend) == 1) return new Tree<int>(*prest);
    else if (distance(inst, inend) == 2) {
        Tree<int> * root = new Tree<int>(*prest);
        root->left = new Tree<int>(*inst);
        return root;
    } else {
        Tree<int> * root = new Tree<int>(*prest);
        vector<int>::iterator rootIt = find(inst, inend, *prest);
        int dist = distance(inst, rootIt);
        root->left = subTree(in, inst, rootIt, pre, prest + 1, prest + 1 + dist);
        root->right = subTree(in, rootIt + 1, inend, pre, prest + 1 + dist, preend);
        return root;
    }
}

Tree<int> * solution(vector<int> inorder, vector<int> preorder) {
    return subTree(inorder, inorder.begin(), inorder.end(), preorder, preorder.begin(), preorder.end());
}
