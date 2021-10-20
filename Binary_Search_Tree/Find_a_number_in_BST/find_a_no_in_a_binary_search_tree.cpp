#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
    }else if(val <= root->data){
        root->left = buildTree(root->left, val);
    }else{
        root->right = buildTree(root->right, val);
    }
    return root;
}

bool search(Node* root, int i){
    if(!root) return false;
    if(root->data == i) return true;
    else if(i <= root->data) return search(root->left, i);
    else return search(root->right, i);
}

void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = buildTree(root, val);
    }
    Inorder(root);
    int i;
    cin>>i;
    if(search(root, i)){
        cout<<"found\n";
    }else{
        cout<<"not found\n";
    }
    return 0;
}