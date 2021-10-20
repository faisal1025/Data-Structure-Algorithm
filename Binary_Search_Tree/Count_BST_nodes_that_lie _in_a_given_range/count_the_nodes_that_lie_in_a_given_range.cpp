// count the number of nodes that lie in a given range

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

Node* createBst(Node* root, int val){
     if(!root) {
         root = new Node(val);
     }
     else if(val >= root->data){
         root->right = createBst(root->right, val);
     }
     else{
         root->left = createBst(root->left, val);
     }
     return root;
}

int cntNode(Node* root, int l, int r){
    static int cnt = 0;
    if(!root) return 0;
    if(root->data >= l && root->data <= r){
        cnt++;
        cntNode(root->left, l, r);
        cntNode(root->right, l, r);
    }
    else if(root->data < l ){
        cntNode(root->right, l, r);
    }
    else{
        cntNode(root->left, l, r);
    }
    return cnt;
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
    int l, r ;
    cin>>l>>r;
    cout<<cntNode(root, l, r);
}