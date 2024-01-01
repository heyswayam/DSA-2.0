#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int _data)
    {   
        this->data=_data;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left!=NULL) q.push(front->left);    //I HAD FORGOT THESE CONDITIONS
            if(front->right!=NULL) q.push(front->right);
        }
    }
    
}
void insertIntoBST1(Node* &root, int val){   //I did using void but bhaiya did using Node* as return type
    if(root == NULL) //empty case (1 case I handled)
    {
        root = new Node(val);
    }
    
    else if(val > root->data ){
        insertIntoBST1(root->right,val);
    }
    else{
        insertIntoBST1(root->left,val);
    }
}

Node* insertIntoBST2(Node* root,int val){
    if(root ==  NULL){
        root = new Node(val);
        return root;
    }

    else if(val> root->data){
        root->right = insertIntoBST2(root->right,val);
    }

    else{
        root->left = insertIntoBST2(root->left,val);
    }
    return root;
}
void takeDataBST(Node* &root){
    cout<<"Enter data: ";
    int val;
    cin>>val;
    while (val!=-1)
    {
        // insertIntoBST1(root,val); //no return type
        root = insertIntoBST2(root,val); //using a return type
        cout<<"Enter data: ";
        cin>>val;
    }
    
}
/////////////// above is creation and traversal code///////////////

int minimum(Node* root){
    int ans;
    if(root == NULL){
        return -1;
    }
    else if(root->left == NULL){
        ans = root->data;
    }
    else
    {
        ans = minimum(root->left);
    }
    return ans;
}
int maximum(Node* root){
    int ans;
    if(root == NULL){   //Empty case
        return -1;
    }
    else if(root->right == NULL){   //1 element case
        ans = root->data;
    }
    else    //recursion
    {
        ans = maximum(root->right);
    }
    return ans;
}

int main()
{
Node* root = NULL;
takeDataBST(root);
cout<<endl;
levelOrderTraversal(root);
cout<<"minimum: "<<minimum(root)<<endl;
cout<<"maximum: "<<maximum(root)<<endl;
return 0;
}