#include<iostream>
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

Node* buildTree(Node* root, int val){
    if(!root){
        root = new Node(val);
    }else if(val <= root->data){
        root->left = buildTree(root->left, val);
    }else{
        root->right = buildTree(root->right, val);
    }
    return root;
}

void Inorder(Node* root){
    if (!root)
    {
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
    
}

Node* findMin(Node* root){
    if(root->left) return findMin(root->left);
    return root;
}

Node* deleteNode(Node* root, int del){
    if(!root) return NULL;
    
    if(root->data == del){
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        else if (root->left && root->right){
            Node* min_node = findMin(root->right);
            root->data = min_node->data;
            root->right = deleteNode(root->right, min_node->data);
        }
        else{
            if(root->left){
                Node* node = root->left;
                delete root;
                return node;
            }
            if(root->right){
                Node* node = root->right;
                delete root;
                return node;
            }
        }
        
    }else if(del <= root->data){
        root->left = deleteNode(root->left, del);
    }else{
        root->right = deleteNode(root->right, del);
    }
    return root;
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
    int del_ele;
    cin>>del_ele;
    deleteNode(root, del_ele);
    Inorder(root);
    return 0;
}