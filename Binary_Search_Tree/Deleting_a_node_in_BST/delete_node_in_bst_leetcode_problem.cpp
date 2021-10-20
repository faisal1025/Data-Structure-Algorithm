/**
 * Definition for a binary tree node.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* findMin(TreeNode* root){
    if(root->left) return findMin(root->left);
    return root;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root; //NULL
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
            
        }
        return root;
    }
};

void Inorder(TreeNode* root){
    if (!root)
    {
        return;
    }

    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
    
}

TreeNode* buildTree(TreeNode* root, int val){
    if(!root){
        root = new TreeNode(val);
    }else if(val <= root->val){
        root->left = buildTree(root->left, val);
    }else{
        root->right = buildTree(root->right, val);
    }
    return root;
}

int main(){
    int n;
    cin>> n;
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        int val;
        cin>>val;
        root = buildTree(root, val);
    }
    cout<<"inorder before delete\t";
    Inorder(root);
    cout<<"\n";
    Solution obj;
    root = obj.deleteNode(root, 3);
    cout<<"inorder after delete\t";
    Inorder(root);
}