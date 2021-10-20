// Finding median in O(n) TC and O(n) SC
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

Node* createBst(Node* root, int val){
    if(!root) {
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

void inorderList(Node* root, vector<int> &list){
    if(!root) return;

    inorderList(root->left, list);
    list.push_back(root->data);
    inorderList(root->right, list);
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
    vector<int> list;
    inorderList(root, list);
    cout<<"Inorder traversal print of the given BST - ";
    for(int i = 0; i < list.size(); i++){
        cout<<list[i]<<" ";
    }
    cout<<endl;
    int median;
    if(n%2 == 0)
        median = (n/2 + (n+1)/2)/2;
    else
        median = (n+1)/2;

    cout<<list[median-1];
}