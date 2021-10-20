#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->right->left = new Node(6);
    root1->right->right = new Node(14);
    root1->right->right->left = new Node(13);
    root1->right->left->left = new Node(4);
    root1->right->left->right = new Node(7);
    /*
                8
              /   \
             3     10
           /     /   \
          1     6    14
              /  \   /
             4    7 13

        DDL : 1 3 8 4 6 7 10 13 14
                     
    */
   inorder(root1);
}
