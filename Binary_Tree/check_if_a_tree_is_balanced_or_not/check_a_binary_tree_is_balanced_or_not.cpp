#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node*  right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool ans;
int height(Node* root){
    if(!root) return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);
    
    int d = lheight - rheight;
    if(d != 1 and d != 0 and d != -1) ans = false;
    
    return max(lheight, rheight) + 1;
}
//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    ans = true;
    height(root);
    return ans;
}



int main(){
    Node* root = new Node(7);
    root->left = new Node(9);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(8);
    root->right->left = new Node(6);
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(9);
    /*
              
                    7
                  /   \
                9       7
              /   \    /   
             8     8   6
           /   \
         10     9

        Ans: Balanced Tree 
        Output: 1
           
    */
   if(isBalanced(root)) cout<<1;
   else cout<<0;

}