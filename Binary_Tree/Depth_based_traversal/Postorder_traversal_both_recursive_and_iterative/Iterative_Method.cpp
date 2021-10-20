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
    Node* curr = root;
    stack<Node*> st;
    stack<int> out;
    st.push(curr);
    while(!st.empty()){
        // in <stack> out values are stored as root, right, left.
        // so that from stack out values out as left, right, root.  
        out.push(curr->data);
        st.pop();
        if(curr->left){
            st.push(curr->left);
        }
        if(curr->right){
            st.push(curr->right);
        }
        if(!st.empty()){
            curr = st.top();
        }
    }

    while(!out.empty()){
        // values out as left, right, root.
        cout<<out.top()<<" ";
        out.pop();
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
        / \   /
       4   5 6

       Postorder: 4 5 2 6 3 1
    */
   postorder(root);

}