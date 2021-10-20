#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* createBst(Node* root, int val){
    if(root == NULL){
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

void morrisInorder(Node* root){
    Node* current = root;
    while(current!= NULL){
        if(!current->left){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            Node* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                predecessor->right = current;
                current = current->left;
            }else{
                predecessor->right = NULL;
                cout<<current->data<<" ";
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
    morrisInorder(root);
}