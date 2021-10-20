#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* createBst(Node* root, int val){
    if(!root) {
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

Node* flattenInLinkedlist(Node* root){
    if(!root) return root;
    if(root->left == NULL && root->right == NULL){
        return root;
    }

    Node* left = flattenInLinkedlist(root->left);
    Node* right = flattenInLinkedlist(root->right);

    if(left){
        root->right = left;
        root->left = NULL;
        Node* curr = root;
        while(curr->right != NULL){
            curr = curr->right;
        }
        curr->right = right;
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    
    Node* res_root = flattenInLinkedlist(root);
    while(res_root){
        cout<<res_root->data<<" ";
        res_root = res_root->right;
    }
}