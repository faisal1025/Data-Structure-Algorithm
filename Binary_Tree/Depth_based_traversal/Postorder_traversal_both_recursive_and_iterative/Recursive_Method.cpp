#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
void postorder(Node* root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
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
       /   \   /
      4     5 6

      Postorder:4 5 2 6 3 1

    */
   postorder(root);
}