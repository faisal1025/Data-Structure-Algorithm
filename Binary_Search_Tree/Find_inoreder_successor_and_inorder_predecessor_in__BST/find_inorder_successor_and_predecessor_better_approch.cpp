#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

Node * createBST(Node* node, int val){
    if(!node){
        node = new Node(val);
    }
    else if(val <= node->data){
        node->left = createBST(node->left, val);
    }
    else{
        node->right = createBST(node->right, val);
    }
    return node;
}

Node* leftmax(Node* root){
    if(root->right) return leftmax(root->right);
    return root;
}
Node* rightmin(Node* root){
    if(root->left) return rightmin(root->left);
    return root;
}

void printSucPre(Node* root, Node* &suc, Node* &pre, int x){
    if(!root) return;

    if(root->data == x){
        if(root->left) pre = leftmax(root->left);
        if(root->right) suc = rightmin(root->right);
        return;
    }
    else if(x < root->data){
        suc = root;
        printSucPre(root->left, suc, pre, x);
    }
    else{
        pre = root;
        printSucPre(root->right, suc, pre, x);
    }
    return;
}

int main(){
    int n;
    Node* root = NULL;
    cin>>n;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = createBST(root, val);
    }
    /*
            3
          /   \
         1     4
       /   \    \
      N     2    5
      
    */
    Inorder(root);
    int x;
    cin>>x;
    Node* suc;
    Node* pre;
    printSucPre(root, suc, pre, x);
    cout<<pre->data<<" "<<suc->data;
    cout<<endl;
}