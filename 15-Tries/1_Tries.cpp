#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char val;
    Node *arr[26];
    bool isTerminal;

    Node(char _val)
    {
        val = _val;
        char ch = val - 'a';
        // arr[ch] = new Node(_val);
        for (int i = 0; i < 26; i++)
        {
            arr[i] = NULL;
        }
        isTerminal = false;
    }
};
void traverse(Node* root){
    if(root==NULL){
        return;
    }
    Node* ans = NULL;
    for (int i = 0; i < 25; i++)
    {
        Node* temp = root->arr[i];
        if(temp!=NULL){
            ans = temp;
            cout<<root->arr[i]->val;
        }
    }
    // traverse(ans);
}

// void insertNode(Node *root, string word)
// {
//     if (word.length() == 0)
//     {
//         root->isTerminal = true;
//         return;
//     }

//     int index = word[0] - 'a';

//     if (root->arr[index] == NULL)
//     {
//         root->arr[index] = new Node(word[0]);
//         insertNode(root->arr[index], word.substr(1));
//     }
//     else
//     {
//         cout<<word[0]<<endl;
//         insertNode(root->arr[index], word.substr(1));
//     }
//     ;
// }

Node* insertNode(Node *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return root;
    }

    int index = word[0] - 'a';

    if (root->arr[index] == NULL)
    {
        root->arr[index] = new Node(word[0]);
    }
    else
    {
        cout<<word[0]<<endl;
    }
        root= insertNode(root->arr[index], word.substr(1));
    
    return root;

}
bool searchWord(Node *root, string word)
{
    if (word.length() == 0 && root->isTerminal == true)
    {
        return true;
    }
    if (word.length() != 0)
    {
        char ch = word[0] - 'a';
        if (root->arr[ch] != NULL)
        {
            searchWord(root->arr[ch], word.substr(1));
        }
    }
    return false;
}
int main()
{
    Node *root = new Node('v');
    root = insertNode(root, "cars");
    // root = insertNode(root, "cared");
    traverse(root);
    // cout << searchWord(root, "cars");
    return 0;
}