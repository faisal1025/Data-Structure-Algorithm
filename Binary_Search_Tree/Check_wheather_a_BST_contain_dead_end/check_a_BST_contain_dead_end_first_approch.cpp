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


bool search(Node* root, int l){
    if(!root) return false;
    if(root->data == l) return true;
    
    if(root->data < l)
        return search(root->right, l);
        
    if(root->data > l)
        return search(root->left, l);
}

bool is_deadEnd;
void isDeadEnd(Node* root, Node* current){
    if(!current->left && !current->right){
        if(current->data-1 == 0){
            if(search(root, current->data+1))
            is_deadEnd = true;
        }
        else{
             if(search(root, current->data+1) && search(root, current->data-1))
                is_deadEnd = true;
        }
    }
    else{
        if(current->left)  isDeadEnd(root, current->left);
        if(current->right) isDeadEnd(root, current->right);
    }
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
    isDeadEnd(root, root);
    cout<<is_deadEnd<<endl;
}
