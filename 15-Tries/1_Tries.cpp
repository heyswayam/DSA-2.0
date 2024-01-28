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
void traverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *ans = NULL;
    for (int i = 0; i < 25; i++)
    {
        Node *temp = root->arr[i];
        if (temp != NULL)
        {
            ans = temp;
            cout << root->arr[i]->val;
            traverse(ans);
        }
    }
}

void insertNode(Node *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';

    if (root->arr[index] == NULL)
    {
        root->arr[index] = new Node(word[0]);
    }
    // else
    // {
    //     cout<<word[0]<<endl;
    // }
    insertNode(root->arr[index], word.substr(1));

    ;
}

// Node* insertNode(Node *root, string word)
// {
//     if (word.length() == 0)
//     {
//         root->isTerminal = true;
//         return root;
//     }

//     int index = word[0] - 'a';

//     if (root->arr[index] == NULL)
//     {
//         root->arr[index] = new Node(word[0]);
//     }
//     else
//     {
//         cout<<word[0]<<endl;
//     }
//         root= insertNode(root->arr[index], word.substr(1));    //here the root is replaced with the children nodes (array)
//     return root;
// }

bool searchWord(Node *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    bool ans = false;
    char ch = word[0] - 'a';
    if (root->arr[ch] != NULL)
    {
        ans = searchWord(root->arr[ch], word.substr(1));
    }
    else
        return false;
    return ans;
}
//Word Suggestion Question
void possibleWords(Node *root, string &probable, vector<string> &ans)
{
    {
        // if (root == NULL) return;
        if (root->isTerminal)
        {
            ans.push_back(probable);
        }

        for (int i = 0; i < 25; i++)
        {
            if (root->arr[i] != NULL)
            {
                probable.push_back(root->arr[i]->val);
                possibleWords(root->arr[i], probable, ans);
                probable.pop_back();
            }
        }
    }
}

void getPrefix(Node *root, string word, vector<string> &ans)
{
    if (word.length() == 0)
    {
        string probable;
        possibleWords(root, probable, ans);
        return;
    }
    int index = word[0] - 'a';

    if (root->arr[index] != NULL)
    {
        getPrefix(root->arr[index], word.substr(1), ans);
    }
    else{
        cout<<"Couldn't find the word"<<endl;
        return;
    }
}
int main()
{
    Node *root = new Node('_');
    insertNode(root, "cr");
    insertNode(root, "cad");
    insertNode(root, "carring");
    insertNode(root, "cater");
    insertNode(root, "care");

    // root = insertNode(root, "cared");
    // traverse(root);
    // cout << searchWord(root, "cad") << endl;

    vector<string> ans;
    string lookUpWord = "loonn";
    getPrefix(root, lookUpWord, ans);
    for (auto &i : ans)
    {
        cout << lookUpWord + i << endl;
    }

    return 0;
}