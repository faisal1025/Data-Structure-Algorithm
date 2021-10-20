#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void leftTreeBoundary(Node* root, vector<Node*> &ans){
    if(!root) return;
    Node* current = root;
    while(current){
        ans.push_back(current);
        if(current->left) current = current->left;
        else if(!current->left) current = current->right;
        
    }
}

void downTreeBoundary(Node* root, vector<Node*> &ans){
    if(!root) return;
    
    if(!root->left && !root->right){
        auto it = find(ans.begin(), ans.end(), root);
        if(it == ans.end()){
            ans.push_back(root);
        }
    }
    
    downTreeBoundary(root->left, ans);
    downTreeBoundary(root->right, ans);
}

void rightTreeBoundary(Node* root, vector<Node*> &ans){
    if(!root) return;
    Node* current = root;
    stack<Node*> st;
    while(current){
        st.push(current);
        if(current->right)current = current->right;
        else if(!current->right)current = current->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}


class Solution {
public:
    vector <int> printBoundary(Node *root)
    {
        vector<int> result;
        vector<Node*> ans;
        if(root == NULL) return result;
        result.push_back(root->data);

        leftTreeBoundary(root->left, ans);
        
        // if the left exist left most leaf node must came in downTree so we remove it from ans after leftTree
        if(root->left)
            ans.erase(ans.begin()+ans.size()-1);

        downTreeBoundary(root, ans);
        
        // if the right most end is a leaf remove it from the ans vector otherwise leave.
        if(root->right)
            ans.erase(ans.begin()+ans.size()-1);
        
        // call the right tree boundary 
        rightTreeBoundary(root->right, ans);

        for(int i = 0; i < ans.size(); i++){
            result.push_back(ans[i]->data);
        }
        return result;
    }
};


int main(){
    Node* root1 = new Node(8);
    root1->left = new Node(3);
    root1->right = new Node(10);
    root1->left->left = new Node(1);
    root1->left->right = new Node(6);
    root1->right->right = new Node(14);
    root1->right->right->left = new Node(13);
    root1->left->right->left = new Node(4);
    root1->left->right->right = new Node(7);
    /*
                8
              /   \
             3     10
           /     /   \
          1     6    14
              /  \   /
             4    7 13

        boundary traversal: 8 3 1 4 7 13 14 10
        
    */
   Solution obj;
   vector<int> result = obj.printBoundary(root1);
   for(int i = 0; i < result.size(); i++){
       cout<<result[i]<<" ";
   }
   
}