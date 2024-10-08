#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        cout << "Enter data for node" << endl;
        cin >> this->data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *createTree()
{
    Node* root=new Node();
    if (root->data == -1)
    {
        return NULL;
    }
    cout << "Enter data for left node" << endl;
    root->left = createTree();
    cout << "Enter data for right node" << endl;
    root->right = createTree();

    return root;
}
int main()
{
    cout << createTree()->right->data << endl;
    return 0;
}