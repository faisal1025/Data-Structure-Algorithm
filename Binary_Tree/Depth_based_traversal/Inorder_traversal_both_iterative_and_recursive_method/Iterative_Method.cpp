#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    stack<Node*> st;
    Node* curr = root;
    while(!st.empty() || curr != NULL){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            cout<<curr->data<<" ";
            curr = curr->right;
            st.pop();
        }
    }
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
         2     3
       /   \
      4     5

      Inorder: 4 2 5 1 3
    */
   inorder(root);    

}