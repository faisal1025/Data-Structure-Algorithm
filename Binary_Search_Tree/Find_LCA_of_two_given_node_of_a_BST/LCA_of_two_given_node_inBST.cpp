#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node * right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// creating BST
Node* createTree (Node* root, int val){
    if(!root) {
        root = new Node(val);
    }else if(val < root->data){
        root->left = createTree(root->left, val);
    }else{
        root->right = createTree(root->right, val);
    }
    return root;
}

// Solution making finding Lowest Common Ansister
class Solution{
    public:
    Node* LCA(Node* root, int n1, int n2){
        if(!root) return root;

        if(root->data == n1 || root->data == n2) return root;
        Node* l = LCA(root->left, n1, n2);
        Node* r = LCA(root->right, n1, n2);
        
        if(l and r) return root;
        else if(l) return l;
        else r;
    }
};
// Solution ends

// Main function
int main(){
    int n;
    Node* root = NULL;
    cin>>n;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        root = createTree(root, val);
    }
    /*
            3
          /   \
         1     4
       /   \    \
      N     2    5
      
    */
    int n1, n2;
    cin>>n1>>n2;
    Solution obj;
    Node* ans = obj.LCA(root, n1, n2);
    cout<<ans->data;
    return 0;
}