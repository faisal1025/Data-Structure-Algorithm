#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* createBst(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = createBst(root->left, val);
    }
    else{
        root->right = createBst(root->right, val);
    }
    return root;
}

Node* maxleft(Node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

void swap(Node *root, Node *pre){
    int temp = root->data;
    root->data = pre->data;
    pre->data = temp;
}

Node* deleteNode(Node* root, int delVal){
    if(!root) return NULL;
    Node* temp = NULL;
    if(root->data == delVal){
        if(!root->left){
            temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* pre = maxleft(root->left);
            swap(root, pre);
            root->left = deleteNode(root->left, delVal);
        }
    }else if(delVal < root->data){
        root->left = deleteNode(root->left, delVal);
    }else{
        root->right = deleteNode(root->right, delVal);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    int n;
    cin>>n;
    Node * root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = createBst(root, val);
    }

    /*
            3
          /   \
         1     4
           \    \
            2    5

        inorder = 1 2 3 4 5
        if delVal = 1
        inorder = 2 3 4 5

    */

    inorder(root);
    int delVal;
    cin>>delVal;

    root = deleteNode(root, delVal);
    inorder(root);
    return 0;
}