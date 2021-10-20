#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node * createBst(Node* root, int val){
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

void sortedList(Node* root, int *arr){
    static int i = 0;
    if(!root) return ;

    sortedList(root->left, arr);
    arr[i++] = root->data;
    sortedList(root->right, arr);
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
    int arr[n];
    sortedList(root, arr);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}