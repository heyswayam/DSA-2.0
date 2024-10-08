Node* solve(Node* root, int &k, int &node, int &ans) {
    if (!root) return nullptr;
    if (root->data == node) return root;
    if(ans!=-1){
        // ans mil chuka h
        return root;
    }

    auto leftAns = solve(root->left, k, node, ans);
    auto rightAns = solve(root->right, k, node, ans);

    if (!leftAns && !rightAns) return nullptr;
    k--;

    if (k == 0) ans = root->data;

    if (leftAns && !rightAns) return leftAns;
    if (!leftAns && rightAns) return rightAns;

    return root;
}

int kthAncestor(Node *root, int k, int node) {
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}