#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    /*
                1
              /   \
             2     3
            / \   /
           4   5 6

           preorder: 1 2 4 5 3 6
    */
   preorder(root);
}