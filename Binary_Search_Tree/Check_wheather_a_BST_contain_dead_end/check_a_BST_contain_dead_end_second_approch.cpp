//A dead end is that leaf node after that no any node can't be inserted from that 
//leaf node.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
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

/*
        8
      /   \
     5     9
    /  \
   2    7
  /
 1

 ans = 1

*/

bool is_deadEnd;
void isDeadEnd(Node* root, Node* &suc, Node* &pre){
    if(!root) return ;
    if(!root->left and !root->right){
        if(suc and pre and suc->data == root->data+1 and pre->data == root->data-1)
        is_deadEnd = true;
        if(suc and suc->data == root->data+1 and root->data-1 == 0)
        is_deadEnd = true;
    }
    
    isDeadEnd(root->left, root, pre);
    isDeadEnd(root->right, suc, root);
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>> val;
        root = createBst(root, val);
    }
    Node* suc = NULL;
    Node* pre = NULL;
    is_deadEnd = false;
    cout<<is_deadEnd<<endl;
    isDeadEnd(root, suc, pre);
    cout<<is_deadEnd<<endl;
}
