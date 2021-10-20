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

void getList(Node* root, vector<int> & list){
    if(root == NULL) return;

    getList(root->left, list);
    list.push_back(root->data);
    getList(root->right, list);
}

Node* BalancedBst(vector<int> &list, int start, int end){
    if(start > end) return NULL;
    int mid = (start+end) / 2;
    Node* root = new Node(list[mid]);
    if(start == end)
        return root;
    root->left = BalancedBst(list, start, mid-1);
    root->right = BalancedBst(list, mid+1, end);
    return root;
}

void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main(){
    Node * root = new Node(2);
    root->left = new Node(4);
    root->left->left = new Node(6);
    vector<int> list;
    getList(root, list);
    
    sort(list.begin(), list.end());
    
    root = BalancedBst(list, 0, list.size()-1);
    Inorder(root);
}