// Morris traversal
// Finding the median of a BST in O(n) TC and O(1) SC.

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

Node* createBst(Node* root, int val){
    if(root == NULL){
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

int morrisTraversal(Node* root){
    int cnt = 0;
    Node* current = root;
    while(current != NULL){
        if(!current->left){
             cnt++;
             cout<<current->data<<" ";
             current = current->right;
        }
        else{
            Node* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                predecessor->right = current;
                current = current->left;
            }
            else{
                predecessor->right = NULL;
                cnt++;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
    return cnt;
}

Node* morrisTraversal2(Node* root, int median){
    int cnt = 0;
    Node* current = root;
    while(current != NULL){
        if(!current->left){
             cnt++;
             if(cnt == median)
                break;
             current = current->right;
        }
        else{
            Node* predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                predecessor->right = current;
                current = current->left;
            }
            else{
                predecessor->right = NULL;
                cnt++;
                if(cnt == median)
                    break;
                current = current->right;
                
            }
        }
    }
    return current;
}

int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    for(int i = 0; i < n ; i++){
        int val;
        cin>>val;
        root = createBst(root, val);
    }
    int size = morrisTraversal(root);
    int median;
    if(size%2 == 0){
        median = (size/2 + (size+1)/2)/2;
    }else{
        median = (size+1)/2;
    }
    Node* ans = morrisTraversal2(root, median);
    cout<<endl;
    cout<<"median of tree - "<<ans->data;
}