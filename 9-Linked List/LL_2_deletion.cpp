#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        // cout<<"Parameterized ctor"<<endl;
        this->next = NULL;
        this->data = data;
    }
};

void deleteAtHead(Node *&head)
{
    Node *temp = head;

    head = head->next;
    temp->next = NULL; //becoz we are good boy and follow GOOD PRACTICE
    delete temp;
}

void printLLReverse(Node *head)
{
    if (head == NULL) // BASE CASE
        return;

    Node *temp = head;
    printLLReverse(temp->next); // RC
    cout << temp->data << " ";  // BACKTRACK
}
void printLL(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(15);
    Node *third = new Node(93);
    Node *fourth = new Node(30);
    Node *head = first;

    first->next = second;
    second->next = third;
    third->next = fourth;

    printLL(first);

    deleteAtHead(head);
    cout << endl;
    printLL(head);

    return 0;
}