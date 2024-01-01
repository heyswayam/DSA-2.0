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

void insertAtHead(Node *&head, int data)
{
    Node *newnode = new Node(data);

    Node *temp = head;

    newnode->next = head;
    head = newnode;
    // delete(newnode);
}
void insertAtTail(Node *&head, int data)
{
    Node *newnode = new Node(data);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    delete(newnode);  // this unallocates the node and set the value as 0
}

int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void insertAtPos(Node *&head, int data, int pos)
{
    int length = getLength(head);
    if (pos <= 1)
        insertAtHead(head, data);
    else if (pos >= length + 1)
        insertAtTail(head, data);
    else
    {
        // Method-1 (no prev node)
        // Node *newnode = new Node(data);
        // Node *temp = head;
        // pos--;
        // while (pos != 1)
        // {
        //     temp = temp->next;
        //     pos--;
        // }
        // newnode->next = temp->next;
        // temp->next = newnode;

        // Method-2 (with curr and prev nodes)
        Node *newnode = new Node(data);
        Node *curr = head;
        Node *prev = NULL;
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        newnode->next = curr;
        prev->next = newnode;
        // delete(newnode);    // this is not giving output
    }
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

    // insertAtHead(head, 23);
    // insertAtTail(head,47);
    // insertAtPos(head, 68, -2);
    // insertAtPos(head, 48, 23);
    insertAtPos(head, 48, 60);
    cout << endl;
    printLL(head);


    return 0;
}