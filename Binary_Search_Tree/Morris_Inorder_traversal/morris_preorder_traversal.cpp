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

Node* createBst(Node* root, int val){
    if(!root){
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

void morrisPreorder(Node* root){
    Node* current = root;
    while(current != NULL){
        if(!current->left){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            Node* predecessor = current->left;
            while(predecessor->right != NULL and predecessor->right != current){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                predecessor->right = current;
                cout<<current->data<<" ";
                current = current->left;
            }
            else{
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = createBst(root, val);
    }
    morrisPreorder(root);
}
