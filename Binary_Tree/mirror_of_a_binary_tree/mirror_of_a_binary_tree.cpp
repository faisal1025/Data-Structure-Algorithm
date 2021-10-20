#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }  
};

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void mirror(Node* root){
    if (root == NULL){ 
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    /*
            1
          /   \
        2       3
       /  \
      4    5
      inorder = 4 2 5 1 3

    mirror:

            1
          /   \
         3     2
             /   \
            5     4
      inorder = 3 1 5 2 4 
    */
   inorder(root);
   cout<<"\n";
   mirror(root);
   inorder(root);
   cout<<"\n";
}
