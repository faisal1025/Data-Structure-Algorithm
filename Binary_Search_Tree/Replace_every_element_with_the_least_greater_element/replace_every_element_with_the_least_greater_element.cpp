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

Node* createBst(Node* root, int val, int ans[], Node* suc, int n){
    static int i =  n-1;
    if(!root) {
        if(suc){
            ans[i--] = suc->data;
        }else{
            ans[i--] = -1;
        }
        root = new Node(val);
    }
    else if(val <= root->data){
        root->left = createBst(root->left, val, ans, root, n);
    }
    else{
        root->right = createBst(root->right, val, ans, suc, n);
    }
    return root;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int ans[n];
    for(int i = n-1; i >= 0; i--){
        Node* suc = NULL;
        root = createBst(root, arr[i], ans, suc, n);
    }
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    // 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28
}