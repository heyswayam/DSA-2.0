#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *createNode()
{
    Node *root = new Node;
    cout << "Enter data: ";
    cin >> root->data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
Node *createBT()
{
    Node *root = createNode();

    if (root->data == -1)
    {
        return NULL;
    }
    cout << "Enter left node " << endl;
    root->left = createBT();
    cout << "Enter right node " << endl;
    root->right = createBT();
    return root;
}
void levelOrderTraversal(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        if (front == NULL )
        {
            q.pop();
            if (q.size()>1)
            {
            q.push(NULL);
            }
            cout << endl;
        }
        else
        {
            cout << front->data << " ";
            q.pop();
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = createBT();

    levelOrderTraversal(root);
    return 0;
}