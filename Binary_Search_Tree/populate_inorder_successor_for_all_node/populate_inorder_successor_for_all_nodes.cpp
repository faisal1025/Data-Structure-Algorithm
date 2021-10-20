#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val){
        data = val;
        next = left = right = NULL;
    }
}*Inroot = NULL;

Node* createTree(Node* root, int val){
    if(!root) {
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = createTree(root->left, val);
    }
    else{
        root->right = createTree(root->right, val);
    }
    return root;
}

void printInorder(Node* root){
    if(!root) return;

    while (root)
    {
        cout<<root->data<<" ";
        root = root->next;
    }
    
}

void Inorder(Node* root, Node* &pre){
    if(root == NULL) return;
    
    Inorder(root->left, pre);
    if(pre != NULL){
        pre->next = root;
    }else{
        Inroot = root;
    }
    pre = root;
    Inorder(root->right, pre);
}

class Solution
{
public:

    void populateNext(Node *root)
    {
        Node* pre = NULL;
        Inorder(root, pre);
    }
};

int main(){
    int n;
    cin>>n;
    Node* root;
    for(int i = 0; i < n ;i++){
        int val;
        cin>>val;
        root = createTree(root, val);
    }
    Solution obj;
    obj.populateNext(root);
    printInorder(Inroot);
}
