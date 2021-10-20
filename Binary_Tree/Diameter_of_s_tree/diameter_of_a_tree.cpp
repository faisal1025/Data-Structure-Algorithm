#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}; 
int max_path;

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    max_path = max(max_path, left+right+1);
    return (max(left, right) + 1);
}

class Solution{
    public:
    int calcDiameter(Node* root){
        max_path = INT_MIN;
        height(root);
        return max_path;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    /*
            1
          /   \
        2       3
      /   \
    4      5
            \
             6
              \ 
               7
    Ans = 6
    */
   Solution obj;
   cout<<obj.calcDiameter(root)<<"\n";

}