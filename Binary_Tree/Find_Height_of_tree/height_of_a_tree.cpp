#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    /*
    logic: keep track of the left child level and the right child level and return the
           maximum(left, right) of both level.
    */
    int height(struct Node* node){
        int left = 1, right = 1;
        if(node == NULL){
            return 0;
        }
        Node* current = node;
        if(current->left){
            left += height(current->left);  
        } 
        
        if(current->right){
            right += height(current->right);
        } 
        if(left >= right)
            return left;
        else
            return right;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    //root->right = new Node(3);
    //root->left->left = new Node(11);
    root->left->right = new Node(10);
    root->left->right->left = new Node(20);
    root->left->right->right = new Node(30);
    root->left->right->right->right = new Node(50);
    /*
            1
          /   \
         2     3
       /   \
      11   10
    */
    Solution obj;
    int ans = obj.height(root);
    cout<<ans;
    return 0;
}