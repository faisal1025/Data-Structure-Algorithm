#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node(int val){
        data = val;
        left = right = next = NULL;
    }
}*inroot = NULL;

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

void inorder(Node* root){
    if(!root){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

class Solution{
    public:
    Node* populateInorderSuccessor(Node* root){

        if(!root) return root;
        Node* left = populateInorderSuccessor(root->left);
        if(left){
            while(left->right){
                left = left->right;
            }
            left->next = root; 
        }
        else if(!inroot){
            inroot = root;
        }
        Node* right = populateInorderSuccessor(root->right);
        if(right){
            while(right->left){
                right = right->left;
            }
            root->next = right;
        }
        return root;
    }
};

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = createBst(root, val);
    }

    // inorder(root);
    Solution obj;
    obj.populateInorderSuccessor(root);
    while(inroot){
         cout<<inroot->data<<" ";
         inroot = inroot->next;
    }
    return 0;
}