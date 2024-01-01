#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int childrenCount;
    Node **children;
    Node(int data)
    {
        this->data = data;
        this->childrenCount = 0;
        this->children = 0;
    }
};
Node *takeInput()
{
    int data, count;
    cout << "Enter the data of root" << endl;
    cin >> data;
    cout << "Enter Children Count for " << data << endl;
    cin >> count;
    Node *root = new Node(data);
    root->childrenCount = count;
    root->children = new Node *[count]; // array to store

    // root->left = takeInput();
    // root->right = takeInput();
    for (int i = 0; i < count; i++)
    {
        root->children[i] = takeInput();
    }
    return root;
}
void levelOrderPrinting(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            for (int i = 0; i < front->childrenCount; i++)
            {
                if (front->children[i] != NULL)
                {
                    q.push(front->children[i]);
                }
            }
        }
    }
}
int main()
{
    Node *root = takeInput();
    levelOrderPrinting(root);
    return 0;
}