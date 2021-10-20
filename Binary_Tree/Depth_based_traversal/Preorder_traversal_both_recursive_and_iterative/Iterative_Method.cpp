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

void preorder(Node* root){
    Node* curr = root;
    stack<Node*>st;
    if(curr != NULL){
        st.push(curr);
    }
    while(!st.empty() || curr != NULL){
        cout<<curr->data<<" ";
        st.pop();
        if(curr->right){
            st.push(curr->right);     
        }
        if(curr->left){
            st.push(curr->left);
        }
        curr = st.top();
    }
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
       /   \  /
      4    5  6

      preorder: 1 2 4 5 3 6

    */
   preorder(root);
}