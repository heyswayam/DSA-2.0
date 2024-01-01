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
    // delete(newnode);
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
        // Method-2 (with curr and prev nodes)
        Node *newnode = new Node(data);
        Node *curr = head;
        Node *prev = NULL;
        while (pos != 1)
        {
            prev->next = curr;
            curr = curr->next;
            pos--;
        }
        newnode->next = curr;
        prev->next = newnode;
        // delete(newnode);    
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

void reverseLL(Node* &head, Node* &prev){
    if(head==NULL){
        cout<<1<<endl;
        return;
    }

    Node* nextNode = head->next;
    // cout<<"hello"<<endl;
    head->next=prev;
    prev=head;

    reverseLL(nextNode,prev);
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
    cout<<endl;
    Node *prev = NULL;

    reverseLL(head,prev);
    cout<<"After reversing: "<<endl;
    printLL(prev);
    
    return 0;
}